openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=sehyan/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

rm ./etc/nginx/sites-available/default
cp ./tmp/default etc/nginx/sites-available/

if [ ${AUTOINDEX} -eq -1 ] ; then
        sed -i 's/autoindex on;/autoindex off;/g' etc/nginx/sites-available/default
fi

cp tmp/phpinfo.php var/www/html/

wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/

cp -rp var/www/html/phpmyadmin/config.sample.inc.php var/www/html/phpmyadmin/config.inc.php

rm var/www/html/phpmyadmin/config.inc.php
cp tmp/config.inc.php var/www/html/phpmyadmin/

wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ var/www/html/
cp ./tmp/wp-config.php var/www/html/wordpress/
chown -R www-data:www-data /var/www/html/wordpress

service mysql start
mysql < var/www/html/phpmyadmin/sql/create_tables.sql

echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root --skip-password
echo "CREATE USER 'ash'@'localhost' IDENTIFIED BY '1234';" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'ash'@'localhost';" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password

service mysql reload
service php7.3-fpm start
service nginx start

bash