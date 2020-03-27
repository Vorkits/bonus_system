from sql import SQL
from tkinter import *
root = Tk()
items={}
POSITIONS={'standart':0,'left':0,'center':200,'right':340}


def generator():
    items['id'].insert(0,'1323')

def add_user():
    
    name=items['name'].get()
    user_id=items['id'].get()
    number=items['number'].get()
    label=items['text_label']
    if name!='' and user_id!=''and number!='':
        result=SQL().user_operation(user_id,name,number)
        
        if result:
            print(SQL().get_users())
            label.config(text='Новый пользователь '+result+' добавлен',fg='green')
            SQL().get_users()
        else:
            label.config(text='Такой пользователь уже есть ',fg='red')
    else:
        label.config(text='Не все поля заполнены')



    
    
def delete_user():
    a=items['delete_number']
    delete_number=a.get()
    label=items['delete_label']
    if delete_number!='':
        
        SQL().user_operation(number=delete_number,delete=True)
        items['delete_number'].delete(0,last='end')
        label.config(text=delete_number+' Успешно удален',fg='green')
        print(SQL().get_users())
    
class BaseItems(object):
    
    @staticmethod
    def u_button(b_text,width,height,color):
        
        
        
        b1 = Button(text=b_text, width=width, height=height,bg=color)
        return b1
    
    @staticmethod
    def u_label(l_text,width,height,color,font_size):
        l1 = Label(text=l_text, font="Arial "+str(font_size),width=width,height=height,bg=color)
        return l1
    
    @staticmethod
    def u_entry(e_text,width,color):
        e1 = Entry(width=width,bg=color)
        return e1
    
    
class AddItems(BaseItems):
    @classmethod
    def add_button(cls,b_text='text',width=1,height=1,color='green',pos_x=0,pos_y=0,position='standart',func=None):
        if position in POSITIONS.keys():
            position=POSITIONS[position]
        else:
            position=0
            
        b=cls.u_button(b_text,width,height,color)
        if func:
            b.config(command=func)
        
        b.place(x=pos_x+position,y=pos_y)
        
        return b
        
    @classmethod
    def add_label(cls,l_text='text',width=1,height=1,color='white',f_size=18,pos_x=0,pos_y=0,position='standart'):
        if position in POSITIONS.keys():
            position=POSITIONS[position]
        else:
            position=0
            
        l=cls.u_label(l_text,width,height,color,font_size=f_size)
        
        l.place(x=pos_x+position,y=pos_y)
        
        return l
    
    @classmethod
    def add_entry(cls,e_text='input',width=1,color='white',pos_x=0,pos_y=0,position='standart'):
        if position in POSITIONS.keys():
            position=POSITIONS[position]
        else:
            position=0
            
        e=cls.u_entry(e_text,width,color)
        
        e.place(x=pos_x+position,y=pos_y)
        
        return e
    
        
class FirstPanel(AddItems):
    show=False
    init=[]
    def __new__(cls):
        if  not hasattr(cls,'instance'):
            cls.instance=super(cls,cls).__new__(cls)
        return cls.instance
    def build(self):
        if self.show==False:
            self.show=True
            add_items=self.__class__
            storage=self.init
            storage.append(add_items.add_label(l_text='',height=600,width=35,color='#C6E2FF'))
            storage.append(add_items.add_label(l_text='',height=600,width=27,color='#FF6960',pos_x=300))
            storage.append(add_items.add_label(l_text='Добавить карту',height=1,width=15,color='#C6E2FF',pos_y=50,pos_x=50,position='left'))
            k=add_items.add_label(l_text='Имя',height=1,width=15,color='#C6E2FF',pos_y=100,pos_x=65,position='left',f_size=14)
            storage.append(k)
            
            k=add_items.add_entry(width=15,color='white',pos_y=125,pos_x=105,position='left')
            storage.append(k)
            items['name']=k
            storage.append(add_items.add_label(l_text='Номер',height=1,width=15,color='#C6E2FF',pos_y=150,pos_x=65,position='left',f_size=14))
            k=add_items.add_entry(width=15,color='white',pos_y=180,pos_x=105,position='left')
            storage.append(k)
            items['number']=k
            storage.append(add_items.add_label(l_text='Номер карты',height=1,width=15,color='#C6E2FF',pos_y=200,pos_x=65,position='left',f_size=14))
            k=add_items.add_entry(width=15,color='white',pos_y=230,pos_x=105,position='left')
            storage.append(k)
            items['id']=k
            storage.append(add_items.add_button(b_text='сгенерировать',width=15,color='white',pos_y=250,pos_x=95,position='left',func=generator))
            k=add_items.add_button(b_text='Добавить',width=20,height=4,color='white',pos_y=290,pos_x=85,position='left',func=add_user)
            storage.append(k)
            k.config(font=("Verdana", 13, "bold"),width=10,height=1)
            k=add_items.add_label(l_text='',height=1,width=15,color='#C6E2FF',pos_y=330,pos_x=0,position='left',f_size=14)
            k.config(font=("Arial", 10),width=35,height=1,fg='red')
            storage.append(k)
            items['text_label']=k
            storage.append(add_items.add_label(l_text='Удалить карту',height=1,width=15,color='#FF6960',pos_y=50,pos_x=0,position='right'))
            storage.append(add_items.add_label(l_text='Номер тел.',height=1,width=15,color='#FF6960',pos_y=100,pos_x=25,position='right',f_size=14))
            k=add_items.add_entry(width=15,color='white',pos_y=130,pos_x=65,position='right')
            storage.append(k)
            items['delete_number']=k
            k=add_items.add_button(b_text='Удалить',width=20,height=4,color='white',pos_y=160,pos_x=45,position='right',func=delete_user)
            storage.append(k)
            k.config(font=("Verdana", 13, "bold"),width=10,height=1)
            k=add_items.add_label(l_text='',height=1,width=15,color='#FF6960',pos_y=200,pos_x=-30,position='right',f_size=14)
            k.config(font=("Arial", 10),width=35,height=1,fg='red')
            storage.append(k)
            a=AddItems.add_button(b_text='Добавление карты',width=20,height=1,color='#90ee90')
            b=AddItems.add_button(b_text='Работа с картой',width=20,height=1,color='#90ee90',pos_x=149)
            a.bind('<Button-1>', lambda event,x=SecondPanel():x.hide())
            b.bind('<Button-1>', lambda event:FirstPanel().hide())
            storage.append(a)
            storage.append(b)
            
            items['delete_label']=k
        
        
    def hide(self):
        if self.show:
            for i in self.init:
                i.destroy()
                
            self.init=[]
            print(self.init)
            self.show=False
            SecondPanel().build()
            
            
            


class SecondPanel(AddItems):
    show=False
    init=[]
    def __new__(cls):
        if  not hasattr(cls,'instance'):
            cls.instance=super(cls,cls).__new__(cls)
        return cls.instance
    def build(self):
        if not self.show:
            self.show=True
            add_items=self.__class__
            storage=self.init
            self.radio=IntVar()
            a=AddItems.add_button(b_text='Добавление карты',width=20,height=1,color='#90ee90')
            b=AddItems.add_button(b_text='Работа с картой',width=20,height=1,color='#90ee90',pos_x=149)
            
            
            a.bind('<Button-1>', lambda event,x=SecondPanel():x.hide())
            b.bind('<Button-1>', lambda event:FirstPanel().hide())
            storage.append(a)
            storage.append(b)
            r=Radiobutton(root, text="сканировать по карте", variable=self.radio, value=1,font='Arial 15')
            r.place(y=40,x=0)
            storage.append(r) 
            
            r=Radiobutton(root, text="сканировать по номеру тел.", variable=self.radio, value=2,font='Arial 15')
            r.config(command=lambda:self.scan_number(r))
            r.place(y=40,x=250)
            storage.append(r)
            
            
    
    def scan_number(self,text,show=True):
        text.config(state='normal')
        storage=self.init
        
        add_items=self.__class__
        if show:
            storage.append(add_items.add_label(l_text='Номер тел.',height=1,width=15,pos_y=100,pos_x=25,position='right',f_size=14))
            k=add_items.add_entry(width=15,color='white',pos_y=130,pos_x=65,position='right')
            storage.append(k)
            
            l=add_items.add_label(l_text='Найти',height=1,width=25,pos_y=185,pos_x=0,position='right',color='white',f_size=11)
            storage.append(l)
            
            b=add_items.add_button(b_text='Найти',height=1,width=15,pos_y=155,pos_x=55,position='right',color='grey')
            b.config(command=lambda:self.work_with_bonus(label=l,entry=k))            
            storage.append(b)
            
            
    def work_with_bonus(self,label,entry):
        
        result=SQL().get_user(number=entry.get())
        print(result)
        if not result:
            label.config(text='Такого пользователя нет')
            return 0
        else:
            label.config(text='Пользователь найден')
    def hide(self):
        if self.show:
            for i in self.init:
                i.destroy()
                
            self.init=[]
            print(self.init)
            self.show=False
            FirstPanel().build()



FirstPanel().build()
root.geometry('600x400')

root.mainloop()
