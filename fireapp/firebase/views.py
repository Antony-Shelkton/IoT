from django.shortcuts import HttpResponse,render
import pyrebase
import os
from pathlib import Path

# Build paths inside the project like this: BASE_DIR / 'subdir'.
BASE_DIR = Path(__file__).resolve().parent.parent
config = {
    "apiKey": "AIzaSyBeJmlm2EDRhWVtOBNkHgts1f9b8nfqItM",
    "authDomain": "django-8b191.firebaseapp.com",
    "projectId": "django-8b191",
    "databaseURL":"https://django-8b191-default-rtdb.firebaseio.com/",
   "storageBucket": "django-8b191.appspot.com",
    "messagingSenderId": "166151533080",
    "appId": "1:166151533080:web:4548762305886ce3d3496d"
}

firebase = pyrebase.initialize_app(config)
authe = firebase.auth()
database = firebase.database()

def home(request):
    Department = database.child("Data").child("Department").get().val()
    Name = database.child("Data").child("Name").get().val()
    RollNo = database.child("Data").child("RollNo").get().val()
    context = {
        "Department":Department,
        "Name":Name,
        "RollNo":RollNo,
    }
    print(BASE_DIR)
    return render(request,"firebase/index.html",context)


