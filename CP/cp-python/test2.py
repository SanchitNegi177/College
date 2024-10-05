data={"one":"this",2:"is","3":"sanchit"}
# print(data["one"])
print(data.get("one",'unavailable'))
# print("\n")
print(data.get(2,'unavailable'))
# print("\n")
print(data.get("3",'unavailable'))
# print("\n")
print(data.get("4",'unavailable'))