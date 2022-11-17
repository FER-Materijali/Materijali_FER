curl -i 127.0.0.1:5000/mojapi/v1.1/vehicles 

curl -i 127.0.0.1:5000/mojapi/v1.1/vehicles/1 

curl -i -H "Content-Type: application/json" -X POST -d "{"""brand""":"""Peugeot"""}" 127.0.0.1:5000/mojapi/v1.1/vehicles 

curl -i -H "Content-Type: application/json" -X PUT -d "{"""rented""":"""True"""}" 127.0.0.1:5000/mojapi/v1.1/vehicles/9

curl -u simon:123 -i -X DELETE 127.0.0.1:5000/mojapi/v1.1/vehicles/9

curl -i 127.0.0.1:5000/mojapi/
timeout /t 1
curl -i 127.0.0.1:5000/mojapi/v1.1/brands/2/model

pause



