
from fastapi import FastAPI

arr = FastAPI()
@arr.get("/",tags=["mylist"])
def show():

    return {"first api program"}