curl -A "Mozilla/24.0" -X GET http://localhost:5000/api/

curl -A "Mozilla/24.0" -X POST --data "password=1234&user=abraham" http://localhost:5000/loginas/abraham

curl -A "Mozilla/24.0" -X UPDATE --data "body=Najbolji dokument ikada!" http://localhost:5000/resursi/abraham

curl -A "Mozilla/24.0" -X GET  http://localhost:5000/resursi/posts

curl -A "Mozilla/24.0" -X DELETE  http://localhost:5000/resursi/abraham

pause

set /p DUMMY=Hit ENTER to continue...



