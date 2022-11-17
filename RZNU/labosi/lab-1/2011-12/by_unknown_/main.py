#!/usr/bin/env python2
# ~*~ coding:utf-8 ~*~

import sqlite3, os.path

from flask import *
from flaskext.markdown import Markdown

db_path = 'bits.db'
app = Flask(__name__)
Markdown(app)

# Dokumentacija dostupna na /api/.
api = [
    {'action': '/',
     'method': 'get',
     'params': '*none*',
     'output': 'text/html',
     'desc': u"Dohvati sadržaj glavne stranice."},

    {'action': '/',
     'method': 'post',
     'params': "**bit** text  \n[**author** text]",
     'output': 'text/html',
     'desc':
u"""
Stvori novu poruku sadržaja **bit** kao korisnik imena **author**.
Ukoliko korisnik imena **author** ne postoji, bit će stvoren kao novi korisnik.
Ukoliko je ime korisnika **author** prazno, pretpostavlja se da je jednako
 *\"anonymous\"*. Nakon operacije vrši *redirect* na /bit/**pid**/, gdje je
**pid** redni broj objavljenog teksta.
"""},

    {'action': '/all/',
     'method': 'get',
     'params': '*none*',
     'output': 'text/html',
     'desc': "Dohvati popis svih postova."},

    {'action': '/users/',
     'method': 'get',
     'params': '*none*',
     'output': 'text/html',
     'desc': "Dohvati popis svih korisnika."},

    {'action': '/bit/**pid**/',
     'method': 'get',
     'params': '**pid** int',
     'output': 'text/html',
     'desc': u"Dohvati tekst pohranjen pod rednim brojem **pid**."},

    {'action': '/bit/**pid**/delete',
     'method': 'post',
     'params': '**pid** int',
     'output': 'text/html',
     'desc':
u"""
Izbriši tekst pohranjen rednim brojem **pid**. Nakon operacije vrši
*redirect* na /all/.
"""},

    {'action': '/user/**uid**/',
     'method': 'get',
     'params': '**uid** int',
     'output': 'text/html',
     'desc': u"Dohvati korisnika pohranjenog pod rednim brojem **uid**."},
]

# Prije obrade zahtjeva, spajamo se na bazu podataka.
@app.before_request
def before_request():
    g.db = sqlite3.connect(db_path)

# Nakon obrade zahtjeva, bilježimo pristup sredstvu i prekidamo vezu s bazom.
@app.teardown_request
def teardown_request(e):
    dnevnik.write("%s\t%s\n" % (request.path, request.user_agent))
    dnevnik.flush()

    # Close database connection, if any.
    if hasattr(g, 'db'):
        g.db.close()

@app.route("/", methods=['GET', 'POST'])
def index():
    if request.method == 'GET':
        return render_template('home.html')
    else:
        # Primamo novi tekst.
        text, author = request.form['bit'], request.form['author'].strip()

        # Tekst mora postojati, inače vraćamo na home.
        if text == '': return redirect('/')

        # Ako je ime prazno, nazovi ga anonimcem.
        author = 'anonymous' if author == '' else author

        # Postoji li već autor u bazi?
        user = get_user_by_name(author)

        # If user doesn't exist, create it before continuing.
        if user is None:
            g.db.execute(
                'INSERT INTO users VALUES (NULL, ?, CURRENT_TIMESTAMP)',
                (author,))
            g.db.commit()
            user = get_user_by_name(author)

        # User now exists. Add the text.
        g.db.execute('INSERT INTO bits VALUES (NULL, ?, CURRENT_TIMESTAMP, ?)',
                     (text, user[0]))
        g.db.commit()

        return redirect('/all/')

@app.route("/users/")
def users():
    us = get_all_users()
    return render_template('users.html', us=us)

@app.route("/user/<int:uid>/")
def user(uid):
    u = get_user_by_id(uid)
    if u is None: abort(404)
    bits = get_posts_by_user(uid)
    return render_template('user.html', user=u, bits=bits)

@app.route("/all/")
def posts():
    bits = get_all_posts()
    return render_template('all.html', bits=bits)

@app.route("/bit/<int:pid>/")
def bit(pid):
    bit = get_post(pid)
    if bit is None: abort(404)
    return render_template('bit.html', bit=bit)

# Izbriši neki post.
@app.route("/bit/<int:pid>/delete", methods=['POST'])
def bit_purge(pid):
    g.db.execute('DELETE FROM bits WHERE id = ?', (pid,))
    g.db.commit()
    return redirect('/all/')

@app.route("/api/", methods=['GET'])
def documentation():
    return render_template('docs.html', api=api)

@app.errorhandler(404)
def page_not_found(e):
    return render_template('page_not_found.html'), 404

def get_all_users():
    c = g.db.cursor()
    c.execute('SELECT * FROM users ORDER BY name ASC')
    users = c.fetchall()
    c.close()
    return users

# Dohvati informacije o korisniku imena name, ili None ako korisnik ne postoji.
def get_user_by_name(name):
    c = g.db.cursor()
    c.execute('SELECT * FROM users WHERE name = ?', (name,))
    user = c.fetchone()
    c.close()
    return None if user is None else user

def get_user_by_id(uid):
    c = g.db.cursor()
    c.execute('SELECT * FROM users WHERE id = ?', (uid,))
    user = c.fetchone()
    c.close()
    return None if user is None else user

# Dohvati sve informacije o svim postovima.
def get_all_posts():
    c = g.db.cursor()
    c.execute(
        '''SELECT bits.id, content, bits.date, author, name FROM bits, users
         WHERE author = users.id ORDER BY bits.id DESC''')
    bits = c.fetchall()
    c.close()
    return bits

def get_posts_by_user(uid):
    c = g.db.cursor()
    c.execute(
        '''SELECT id, content, date FROM bits
         WHERE author = ? ORDER BY id DESC''', (uid,))
    bits = c.fetchall()
    c.close()
    return bits

# Dohvati sve potrebne informacije o nekom postu.
def get_post(pid):
    c = g.db.cursor()
    c.execute(
      '''SELECT bits.id, content, bits.date, author, name FROM bits, users
         WHERE author = users.id AND bits.id = ?''', (pid,))
    bit = c.fetchone()
    c.close()
    return bit

# Creates a db schema and populates the db with some initial data.
def init_db():
    conn = sqlite3.connect(db_path)
    c = conn.cursor()

    # Stvori tablicu korisnika i par defaultnih korisnika.
    c.execute('''CREATE TABLE users
                 (id INTEGER PRIMARY KEY ASC,
                  name TEXT,
                  date DATE)''')

    c.executemany('INSERT INTO users VALUES (NULL, ?, CURRENT_TIMESTAMP)',
                  [('admin',), ('clueless12',)])

    # Stvori tablicu postova i neke defaultne postove.
    c.execute('''CREATE TABLE bits
                 (id INTEGER PRIMARY KEY ASC,
                  content TEXT,
                  date DATE,
                  author INTEGER,
                  FOREIGN KEY(author) REFERENCES users(id))''')

    b1 = "I'm the *first and default* post. I was created with the database."
    b2 = '\n\n'.join([
      u"Ja sam drugi defaultni post. Isto sam stvoren zajedno s bazom.",
      u"Ali ipak se **malčice** razlikujem, jer pisan sam na hrvatskom jeziku.",
      u"Tako da sadržim riječi poput čušpajz i grožđe."])

    c.executemany('INSERT INTO bits VALUES (NULL, ?, CURRENT_TIMESTAMP, ?)',
                  [(b1, 1), (b2, 2)])

    conn.commit()
    conn.close()

if __name__ == "__main__":
    if not os.path.exists(db_path): init_db()
    dnevnik = open('dnevnik.log', 'a')
    app.run(debug=True, host='0.0.0.0')
