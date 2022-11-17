from flask import Flask, session, redirect, url_for, escape, request, render_template
from flask.ext.wtf import Form
from wtforms import TextField, BooleanField
from wtforms.validators import Required
from flask.ext.sqlalchemy import SQLAlchemy


app = Flask(__name__)
app.config.from_object('config')
db = SQLAlchemy(app)



class LoginForm(Form):
    user = TextField('user', validators = [Required()])
    password = TextField('password', validators = [Required()])

class User(db.Model):
    id = db.Column(db.Integer, primary_key = True)
    user = db.Column(db.String(64), index = True, unique = True)
    password = db.Column(db.String(64), index = True, unique = True)

    def __repr__(self):
        return '<User %r>' % (self.nickname)
    

@app.route('/')
def index():
    if 'username' in session:
        print 'Logged in as %s' % escape(session['username'])
    return render_template("index.html",title = 'Home')

@app.route('/home')
def home():
    return render_template("base.html",title = 'Home')

@app.route('/login', methods=['GET', 'POST'])
def login():
    form = LoginForm()
    if form.validate_on_submit():
        return redirect(url_for('home'))
    return render_template('forms.html', title = 'Sign In',form = form)
    #return redirect(url_for('home'))

@app.route('/logout')
def logout():
    # remove the username from the session if it's there
    session.pop('username', None)
    return redirect(url_for('index'))

# set the secret key.  keep this really secret:
app.secret_key = 'A0Zr98j/3yX R~XHH!jmN]LWX/,?RT'

if __name__ == '__main__':
    app.run(debug=False)
