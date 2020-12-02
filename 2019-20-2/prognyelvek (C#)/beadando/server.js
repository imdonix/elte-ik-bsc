const PORT = process.env.PORT || 3000;
const DATABASE = " TODO "
const VERSION = { "api" : "1.0", "client" : "1.0" }

const express = require('express');
const bodyParser= require('body-parser');
const path = require('path');
const mongodb = require('mongodb');
const crypto = require('crypto');
const shortid = require('shortid');

const client = mongodb.MongoClient;
const app = express();

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());




app.post('/auth', (req,res) =>
{
    var filter = {
        "neptun" : req.body.neptun || "", 
        "password" : createHash(req.body.password) || ""
    };

    var key = createHash(shortid.generate());

    getCollection("Users", (col,db) => col.findOne(filter, { projection: { key: 0 }}, (err, doc) => 
    {
        if(err || doc == null) res.status(403).send("Hibás adatokat adtál meg");
        else
            col.updateOne(filter, { $set : { "key" : key }}, (err, updateresoult) =>
            {
                if(err) res.status(400).send("Something went wrond!");
                else res.send({"key" : key, "user" : doc});
                db.close();
            })
    }))
})

app.post("/users", (req,res) =>
{
    req.body.forEach(u => {u.password = createHash(u.password)});
    getCollection("Users", (col,db) => col.insertMany(req.body, (err, r) =>
    {
        if(err)
        {
            console.error(err);
            res.status(400).send("Something went wrond!");
        }
        else 
        {
            console.log("Users added to the database!");
            res.send("New elements inserted: " + r.insertedCount);
        }
        db.close();
    }))
})

app.post("/resoults", (req,res) =>
{
    getCollection("Resoults", (col,db) => col.insertOne(req.body, (err, r) =>
    {
        if(err)
        {
            console.error(err);
            res.status(400).send("Something went wrond!");
        }
        else 
        {
            console.log("Result added to the database!");
            res.send("New elements inserted: " + r.insertedCount);
        }
        db.close();
    }))
})

app.post("/exams", (req,res) =>
{
    var questions = req.body.questions;
    getCollection("Questions", (col,db) => col.insertMany(questions, (err,r) =>
    {
        var body = req.body;
        body.questions = body.questions.map(u => u._id);
        getCollection("Exams", (col,db) => col.insertOne(body, (err, r) =>
        {
            if(err)
            {
                console.error(err);
                res.status(400).send("Something went wrond!");
            }
            else 
            {
                console.log("Exam added to the database!");
                res.send("New elements inserted: " + r.insertedCount);
            }
            db.close();
        }))
    }))

})

app.get('/delete/:id', (req, res) => 
{
    var query = {"_id": new mongodb.ObjectID(req.params["id"])}
    getCollection("Exams", (col,db) => col.deleteOne(query, (err, r) =>
    {
        if(err)
        {
            console.error(err);
            res.status(400).send("Something went wrond!");
        }
        else 
        {
            console.log("Exam deleted from the database!");
            res.send("An item has removed from database");
        }
        db.close();
    }))
})


app.get('/', (req, res) => {res.send(VERSION)})
app.get('/exams', (_, res) => returnAllDocument("Exams", res));
app.get('/questions', (_, res) => returnAllDocument("Questions", res));
app.get('/resoults', (_, res) => returnAllDocument("Resoults", res));


app.listen(PORT, () => console.log("App is running on " + PORT));


function getCollection(collection, callback)
{
    client.connect(DATABASE, {useUnifiedTopology: true}, 
    (err, db) =>
    {
        if (err) throw err;
        var dbo = db.db();
        callback(dbo.collection(collection), db);
    }); 
}

function returnAllDocument(collection, res)
{
    getCollection(collection, (col, db) => 
    {
        col.find({}).toArray((err, doc) =>
        {
            if (err) res.status(400).send("Something went wrond!");
            else res.send(doc);
            db.close();
        })
    })
}

function createHash(data)
{
    return crypto.createHash('md5').update(data).digest("hex");
}