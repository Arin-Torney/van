import tkinter
top = tkinter.Tk()
top.title("Van")
canvas = tkinter.Canvas(top, bg="white")
line = canvas.create_line(0, 500, 500, 500)
rect = canvas.create_rectangle(20, 20, 140, 100)
myRect = canvas.create_rectangle(30, 30, 55, 55)
yRect = canvas.create_rectangle(105, 30, 130, 55)
midRect = canvas.create_rectangle(68.125, 30, 93.125, 55)
vanLight = canvas.create_rectangle(20, 60, 25, 80)
firstWheel = canvas.create_oval(30, 100, 55, 125)
secondWheel = canvas.create_oval(105, 100, 130, 125)
canvas.pack()
top.mainloop()
