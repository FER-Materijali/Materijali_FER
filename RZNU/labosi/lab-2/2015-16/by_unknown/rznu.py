from flask import Flask, jsonify, abort, request, render_template
from flask_httpauth import HTTPBasicAuth

app = Flask(__name__)
auth = HTTPBasicAuth()

list = [
	{
		'id' : 1,
		'brand' : u'Citroen',
		'brandid': 1,
		'subbrand' : u'C1',
		'description' : u'kompakt',
		'rented' : False
	},
	{
		'id' : 2,
		'brand' : u'Citroen',
		'brandid': 1,
		'subbrand' : u'C2',
		'description' : u'sportsko vozilo',
		'rented' : False
	},
	{	'id' : 3,
		'brand' : u'Peugeot',
		'brandid': 2,
		'subbrand' : u'307',
		'description' : u'malo gradsko vozilo',
		'rented' : False
	},
	{	'id' : 4,
		'brand' : u'Peugeot',
		'brandid': 2,
		'subbrand' : u'508',
		'description' : u'veliko gradsko vozilo',
		'rented' : False
	},
	{	'id' : 5,
		'brand' : u'Renault',
		'brandid': 3,
		'subbrand' : u'Captur',
		'description' : u'luksuzno vozilo',
		'rented' : False
	},
	{	'id' : 6,
		'brand' : u'Renault',
		'brandid': 3,
		'subbrand' : u'Clio',
		'description' : u'malo gradsko vozilo',
		'rented' : False
	},
	{	'id' : 7,
		'brand' : u'Opel',
		'brandid': 4,
		'subbrand' : u'Insignia',
		'description' : u'direktorsko vozilo',
		'rented' : False
	},
	{	'id' : 8,
		'brand' : u'Opel',
		'brandid': 4,
		'subbrand' : u'Adam',
		'description' : u'gradsko urbano vozilo',
		'rented' : False
	}
	]
	
brands = [
	{
		'id' : 1,
		'brand' : u'Citroen',
	},
	{
		'id' : 2,
		'brand' : u'Peugeot',
	},
	{
		'id' : 3,
		'brand' : u'Renault',
	},
	{
		'id' : 4,
		'brand' : u'Opel',
	}	
	]
	
@app.route('/mojapi/')
def mojapi():
	log = open("dnevnik.txt","a")
	log.write('/mojapi/    '+request.headers.get('User-Agent')+'\n')
	log.close()
	return render_template("mojapi.html",title = 'API')
	
@app.route('/mojapi/v1.1/mapreduce1')
def mapreduce1():
	log = open("dnevnik.txt","a")
	log.write('/mojapi/v1.1/mapreduce1    '+request.headers.get('User-Agent')+'\n')
	log.close()
	with open("mapreduce1.txt", "r") as f:
		content = f.read()
	return render_template("mapreduce.html",title = 'MapReduce',content=content)

@app.route('/mojapi/v1.1/mapreduce2')
def mapreduce2():
	log = open("dnevnik.txt","a")
	log.write('/mojapi/v1.1/mapreduce2    '+request.headers.get('User-Agent')+'\n')
	log.close()
	with open("mapreduce2.txt", "r") as f:
		content = f.read()
	return render_template("mapreduce.html",title = 'MapReduce',content=content)



@app.route('/mojapi/v1.1/vehicles', methods=['GET'])
def list_vehicles():
	log = open("dnevnik.txt","a")
	log.write('/vehicles/    '+request.headers.get('User-Agent')+'\n')
	log.close()
	return jsonify({
		'list' : list
		})

@app.route('/mojapi/v1.1/agent', methods=['GET'])
def list_user_agent():
	log = open("dnevnik.txt","a")
	log.write('/agent/    '+request.headers.get('User-Agent')+'\n')
	log.close()
	return request.headers.get('User-Agent')
	


	 



@app.route('/mojapi/v1.1/vehicles/<int:vehicle_id>', methods=['GET'])
def list_vehicle(vehicle_id):
	log = open("dnevnik.txt","a")
	log.write('/vehicles/'+str(vehicle_id)+'    '+request.headers.get('User-Agent')+'\n')
	log.close()
	vehicle = [vehicle for vehicle in list if vehicle['id'] == vehicle_id]
	if len(vehicle) == 0:
		abort(404)
	return jsonify({
		'vehicle' : vehicle[0]
	})
	
@app.route('/mojapi/v1.1/brands/<int:brand_id>', methods=['GET'])
def list_subbrands(brand_id):
	log = open("dnevnik.txt","a")
	log.write('/vehicles/'+str(brand_id)+'    '+request.headers.get('User-Agent')+'\n')
	log.close()
	brandid = [vehicle for vehicle in brands if vehicle['id'] == brand_id]
	if len(brandid) == 0:
		abort(404)
		
	return jsonify({
			'brand' : brandid
	})
	
@app.route('/mojapi/v1.1/brands/<int:brand_id>/model', methods=['GET'])
def list_subbrands_model(brand_id):
	log = open("dnevnik.txt","a")
	log.write('/vehicles/'+str(brand_id)+'/model    '+request.headers.get('User-Agent')+'\n')
	log.close()
	brandid = [vehicle for vehicle in list if vehicle['brandid'] == brand_id]
	
	if len(brandid) == 0:
		abort(404)
		
	return jsonify({
			'brand' : brandid
	})


@app.route('/mojapi/v1.1/vehicles', methods=['POST'])
def add_vehicle():
	log = open("dnevnik.txt","a")
	log.write('/vehicles/    '+request.headers.get('User-Agent')+'\n')
	log.close()
	if not request.json or not 'brand' in request.json:
		abort(400)
	vehicle = {
		'id': list[-1]['id']+1,
		'brand': request.json['brand'],
		'subbrand': request.json.get('subbrand',""),
		'description': request.json.get('description',""),
		'rented': False
		}
	list.append(vehicle)
	return jsonify({'vehicle' : vehicle }), 201
	
@app.route('/mojapi/v1.1/vehicles/<int:vehicle_id>', methods=['PUT'])
def update_vehicle(vehicle_id):
	log = open("dnevnik.txt","a")
	log.write('/vehicles/'+str(vehicle_id)+'    '+request.headers.get('User-Agent')+'\n')
	log.close()
	vehicle = [vehicle for vehicle in list if vehicle['id'] == vehicle_id]
	if len(vehicle) == 0:
		abort(404)
	if not request.json:
		abort(400)
	vehicle[0]['brand'] = request.json.get('brand', vehicle[0]['brand'])
	vehicle[0]['subbrand'] = request.json.get('subbrand', vehicle[0]['subbrand'])
	vehicle[0]['description'] = request.json.get('description', vehicle[0]['description'])
	vehicle[0]['rented'] = request.json.get('rented', vehicle[0]['rented'])
	return jsonify({'vehicle': vehicle[0]})
	
@app.route('/mojapi/v1.1/vehicles/<int:vehicle_id>', methods=['DELETE'])
@auth.login_required
def delete_vehicle(vehicle_id):
	log = open("dnevnik.txt","a")
	log.write('/vehicles/'+str(vehicle_id)+'    '+request.headers.get('User-Agent')+'\n')
	log.close()
	vehicle = [vehicle for vehicle in list if vehicle['id'] == vehicle_id]
	if len(vehicle) == 0:
		abort(404)
	list.remove(vehicle[0])
	return jsonify({'remove': True})
	
	
users = {
	"simon": "123",
	"tin": "123",
	"test": "123"
	}
	
@auth.get_password
def get_passwpord(username):
	if username in users:
		return users.get(username)
	return None


if __name__ == '__main__':
    app.run()