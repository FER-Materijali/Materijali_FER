from flask import Flask, session, redirect, url_for, escape, request, render_template
from flask.ext.wtf import Form
from wtforms import TextField, BooleanField
from wtforms.validators import Required
from flask.ext.testing import TestCase


app = Flask(__name__)
app.config.from_object('config')

with app.test_request_context('/index', method='GET'):
    assert request.path == '/index'
    assert request.method == 'GET'

cuser=""
cpass=""
maxpost=0

def readFile(name):
    f = open(name,"r")
    return f
def writeFile(name,data):
    fo = open(name, "w")
    for d in data:
        fo.write(data);

class MyTest(TestCase):
    def create_app(self):
        app = Flask(__name__)
        app.config['TESTING'] = True
        return app

class LoginForm(Form):
    user = TextField('user', validators = [Required()])
    password = TextField('password', validators = [Required()])

class PostForm(Form):
    text = TextField('post', validators = [Required()])

@app.route('/api/')
def api():
    log=open("log.txt","a")
    log.write( '/app_interface/  '+request.user_agent.browser+'\n')
    log.close()
    return render_template("api.html",title = 'API')

@app.route('/')
def mainpage():	
    log=open("log.txt","a")
    log.write( '/  '+request.user_agent.browser+'\n')
    log.close()
    return redirect(url_for('index'))

@app.route('/index')
def index():
    log=open("log.txt","a")
    log.write( '/index  '+request.user_agent.browser+'\n')
    log.close()
    return render_template("index.html",title = 'Home')

@app.route('/home')
def home():
    log=open("log.txt","a")
    log.write( '/home  '+request.user_agent.browser+'\n')
    log.close()
    global cuser
    global cpass
    print cuser,cpass
    if cuser=="":
        return redirect(url_for('index'))
    return render_template("base.html",title = 'Home',cuser=cuser)



@app.route('/loginas/<user>', methods=['GET', 'POST', 'DELETE', 'UPDATE'])
def loginas(user):
    if request.method == 'POST':
        return (' You have been succesfully logged in as user: "%s"\n Your password was succesfully validated.' % user )
    return render_template("index.html")

@app.route('/resursi/<ime>', methods=['GET', 'POST', 'DELETE', 'UPDATE'])
def resursi(ime):
    if request.method == 'POST' or request.method == 'UPDATE':
        newData = request.form.__getitem__('body')
        filePath = str(ime)
        filePath += '.txt'
        newFile = open(filePath, 'w')
        newFile.write(str(newData))
        return (' You have created/updated the file named: "%s.txt"\n ' % ime )
    if request.method == 'GET' :
        filePath=str(ime) + '.txt'
        f = readFile(filePath)
        fileData = str(f.read())
        returnData = "You have requested a resource!\n\nName:" +str(filePath)+"\nData:\n" + str(fileData)
        #returnData = "123"
        return (returnData)
    if request.method == 'DELETE':
        #newData = request.form.__getitem__('body')
        filePath = str(ime)
        filePath += '.txt'
        newFile = open(filePath, 'w')
        newFile.write('')
        return (' You have deleted all data from file: "%s"\n ' % filePath )
    return render_template("index.html")

@app.route('/users/')
def users():
    global cuser
    log=open("log.txt","a")
    log.write( '/users/  '+request.user_agent.browser+'\n')
    log.close()
    if cuser=="":
        return redirect(url_for('index'))
    users=[]
    f=readFile("users.txt")
    for line in f.readlines():
        temp=line.split(":")
        users.append(temp[0])
    return render_template("users.html",title = 'USERS',line=users,cuser=cuser)

@app.route('/users/<user>')
def userpage(user):
    posts=[]
    log=open("log.txt","a")
    text=""
    text+="/users/"
    text+=str(user)
    text+="  "
    text+=request.user_agent.browser
    text+="\n"
    log.write(text)
    log.close()
    global cuser
    if cuser=="":
        return redirect(url_for('index'))
    f=readFile("posts.txt")
    for line in f.readlines():
        temp=line.split(":")
        if temp[1]==user:
            posts.append(temp[2])
    return render_template("user.html",title = 'Userpage',user=user,line=posts,cuser=cuser)

@app.route('/posts/<post_id>')
def post(post_id):
    log=open("log.txt","a")
    log.write( '/posts/'+str(post_id)+'  '+request.user_agent.browser+'\n')
    log.close()
    global cuser
    if cuser=="":
        return redirect(url_for('index'))

    posts=[]
    f=readFile("posts.txt")
    for line in f.readlines():
        temp=line.split(":")
        if temp[0]==post_id:
            posts.append(str(temp[1])+":"+str(temp[2]))
    return render_template("post.html",title = 'POSTS',line=posts,cuser=cuser)

@app.route('/posts/')
def posts():
    log=open("log.txt","a")
    log.write( '/posts/  '+request.user_agent.browser+'\n')
    log.close()
    global cuser
    if cuser=="":
        return redirect(url_for('index'))
    posts=[]
    numbers=[]
    f=readFile("posts.txt")
    for line in f.readlines():
        temp=line.split(":")
        numbers.append(temp[0])
        posts.append(line)
    return render_template("posts.html",title = 'POSTS',line=posts,cuser=cuser,numbers=numbers)

@app.route('/posts/deletepost', methods=['GET', 'POST'])
def deletepost():
    log=open("log.txt","a")
    log.write( '/posts/deletepost  '+request.user_agent.browser+'\n')
    log.close()
    global cuser
    if cuser=="":
        return redirect(url_for('index'))
    count=0
    count2=0
    posts=[]
    allPosts=[]
    form = PostForm()
    f=readFile("posts.txt")
    for line in f.readlines():
        temp=line.split(":")
        if temp[1]==cuser:
            count+=1
            posts.append(temp[2])
    f.close()
    f=readFile("posts.txt")
    if request.method=='POST':
       if form.validate_on_submit():
           toDelete=int(request.form['text'])
           for line in f.readlines():
               temp=line.split(":")
               if temp[1]==cuser:
                   count2+=1
                   if count2==toDelete:
                       pass
                   else:
                       allPosts.append(line)
               else:
                   allPosts.append(line)
           #write file
           fo = open("posts.txt", "w")
           for d in allPosts:
               fo.write(d);
           #stop writing 
           return redirect(url_for('posts'))
    return render_template("deletepost.html",title = 'Delete Post',form=form,cuser=cuser,count=count,posts=posts)

@app.route('/posts/newpost', methods=['GET', 'POST'])
def newpost():
    log=open("log.txt","a")
    log.write( '/posts/newpost  '+request.user_agent.browser+'\n')
    log.close()
    global maxpost
    global cuser
    if cuser=="":
        return redirect(url_for('index'))
    ctext=""
    posts=[]
    f=readFile("posts.txt")
    for line in f.readlines():
        temp=line.split(":")
        if maxpost<int(temp[0]):
            maxpost=int(temp[0])
        posts.append(line)
    form = PostForm()
    if request.method=='POST':
        if form.validate_on_submit():
            ctext=request.form['text']
            print ctext
            posts.append(str(maxpost+1)+":"+cuser+":"+ctext+"\n")
            #write file
            fo = open("posts.txt", "w")
            for d in posts:
                fo.write(d);
            #stop writing
            return redirect(url_for('posts'))
    return render_template("newpost.html",title = 'New Post',form=form,cuser=cuser)

@app.route('/login', methods=['GET', 'POST'])
def login():
    log=open("log.txt","a")
    log.write( '/login  '+request.user_agent.browser+'\n')
    log.close()
    global cuser
    global cpass
    users=[]
    count=0
    wrong=0
    form = LoginForm()
    if request.method=='POST':
        if form.validate_on_submit():
           cuser=request.form['user']
           cpass=request.form['password']
           f=readFile("users.txt")
           for line in f.readlines():
               users.append(line)
               temp=line.split(":")
               if temp[0]==cuser:
                   count=1
                   print "User ",cuser," exists."
                   if cmp(temp[1].rstrip(),cpass)==0:
                       pass
                   else:
                       print "Pass :",cpass,": for",cuser," is wrong. Should be: :",temp[1].rstrip(),":"
                       wrong=1    
           if count==0:
               print "User ",cuser," doesn't exist; created user ",cuser,"."
               users.append(cuser+":"+cpass+"\n")
           #write file
           fo = open("users.txt", "w")
           for d in users:
               fo.write(d);
           #stop writing
           print users
           if wrong==1:
               return redirect(url_for('index'))
           else:  
               return redirect(url_for('home'))
    return render_template('forms.html', title = 'Sign In',form = form,cuser=cuser)
    #return redirect(url_for('home'))

@app.route('/logout')
def logout():
    log=open("log.txt","a")
    log.write( '/logout  '+request.user_agent.browser+'\n')
    log.close()
    # remove the username from the session if it's there
    session.pop('user', None)
    global cuser
    global cpass
    cuser=""
    cpass=""
    return redirect(url_for('index'))

# set the secret key.  keep this really secret:
app.secret_key = 'A0Zr98j/3yX R~XHH!jmN]LWX/,?RT'

if __name__ == '__main__':
    app.run(debug=False)
