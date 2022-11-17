var express = require('express')
var app = express()
var path = require('path')

var homeRouter = require('./routes/home.routes')
var itemRouter = require('./routes/item.routes')
var orderRouter = require('./routes/order.routes')

app.set('views', path.join(__dirname, 'views'))
app.set('view engine', 'ejs')

app.use(express.static(path.join(__dirname, 'public')))

app.use(express.urlencoded({extended: true}))

app.use('/', homeRouter)
app.use('/item', itemRouter)
app.use('/order', orderRouter)

app.listen(3000)