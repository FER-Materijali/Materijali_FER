#!/usr/bin/env python2
# ~*~ coding:utf-8 ~*~

from subprocess import call
from random import randint

res_path = 'curl.last.code'

def curl(path, args):
    form = '%{http_code} %{url_effective}'
    args += ' -L --output curl.last.fetched -w "%s" > %s' % (form, res_path)
    return call("curl http://localhost:5000%s %s" % (path, args), shell=True)

def read_result():
    f = open(res_path, 'r')
    res = f.read().split()
    f.close()

    d, form = {}, 'code path'.split()
    for f, i in zip(form, range(0, len(form))):
        d[f] = res[i]

    d['path'] = d['path'].split(':5000')[1]
    return d

def test(t):
    ret = curl(t['path'], t['args'])
    res = read_result()
    fin = True # We assume success.

    for m in t['methods']:
        # Does the curl return code need to be 0?
        if m == 'true': fin = fin and (ret == 0)

        # Does the http response code need to be 200?
        elif m == '200': fin = fin and (res['code'] == '200')

        # Do we need to finish at a certain path?
        elif m[0] == '/': fin = fin and (res['path'] == m)

    return fin

tests = {
    'viewing all users': {
        'methods': 'true 200 /users/'.split(),
        'path': '/users/',
        'args': "-s -G"
        },

    'anonymous posting': {
        'methods': ['true', '200', '/all/'],
        'path': '/',
        'args': "-s -F 'bit=Testing anonymous posting.' -F 'author='",
        },

    'creating a new user': {
        'methods': 'true 200 /all/'.split(),
        'path': '/',
        'args': "-s -F 'bit=Hello world! I are new user lol.' " +
                "-F 'author=tester%d'" % randint(1, 1000000)
        },

    'viewing all posts': {
        'methods': 'true 200 /all/'.split(),
        'path': '/all/',
        'args': "-s -G"
        },

    'posting as existing user': {
        'methods': 'true 200 /all/'.split(),
        'path': '/',
        'args': "-s -F 'bit=%s' -F 'author=%s'" % (
            "Posting this as an existing user.", 'admin')
        },

    'posting non-ascii characters': {
        'methods': 'true 200 /all/'.split(),
        'path': '/',
        'args': "-s -F 'bit=%s' -F 'author=non-ascii'" %
            "Čušpajz, grožđe, 我愛你那麼多."
        }
}

if __name__ == '__main__':
    for name, t in tests.items():
        print "%s: %s" % (name, 'success' if test(t) else 'FAILURE')
