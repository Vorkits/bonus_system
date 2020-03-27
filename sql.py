import yadisk
import time
import os
import sqlite3

SHOPS=['grandpark','snaryaga']#snaryaga,grandpark,nn
SHOP='nn'
y = yadisk.YaDisk(token="AgAAAAAbq87zAAY94cZG_utJbUw4qDHJf3NT1WY")
__author__='Rybkin'
class SQL(object):
    def check_date(self):
        pass
    def __new__(cls):
        if not hasattr(cls, 'instance'):
            try:
                cls.instance = super().__new__(cls)
                ob=cls.instance
                ob.name=SHOP
                conn=sqlite3.connect('{}.db'.format(ob.name))
                cursor=conn.cursor()
                cursor.execute("""CREATE TABLE {}(
                id INTEGER PRIMARY KEY,
                name VARCHAR(50),
                phone VARCHAR(50),
                bonus INTEGER);""".format(ob.name))
                conn.commit()
                conn.close()
            except sqlite3.OperationalError:
                pass
            
        return cls.instance
    def add_to_base(self):
        
        
        for i in SHOPS:
            if i!=SHOP:
                try:
                    y.download("/снаряга/{}.db".format(i), "{}.db".format(i))
                except Exception as e:
                    print(e)
        
        
        base_len=len(self.get_users())
        append_array=[]
        for i in SHOPS:
            try:
                conn=sqlite3.connect('{}.db'.format(i))
                
                cursor=conn.cursor()
                result=cursor.execute("SELECT * FROM {}".format(i)).fetchall()
            
                
                if len(result)>base_len:
                    for j in result[base_len-1:]:
                        append_array.append(j)
                conn.close()
            except Exception as e:
                print(e)
                conn.close()
        
        
        self.append_to_base(append_array)
        for i in SHOPS:
            try:
                os.remove("{}.db".format(i))
            except Exception as e:
                print(e)
        
        try:
            
            y.remove("/снаряга/{}.db".format(SHOP), permanently=True)
        except:
            print('not removed from disk')
        
        with open("{}.db".format(SHOP), "rb") as f:
            y.upload(f, "/снаряга/{}.db".format(SHOP))
        
                    
    def append_to_base(self,array):
        for i in array:
            self.user_operation(i[0],i[1],i[2],i[3])
        
        
            
    def _connect(self)->'connect':
        try:
            conn = sqlite3.connect('{}.db'.format(self.name))
        except:
            print('connect error')
        return conn
    
    def get_users(self):
        conn=self._connect()
        cursor=conn.cursor()
        result=cursor.execute("SELECT * FROM {}".format(self.name)).fetchall()
        conn.close()
        return result
    
    def get_user(self,number=None,id=None):
        conn=self._connect()
        cursor=conn.cursor()
        result=cursor.execute("SELECT * FROM {} WHERE phone='{}'".format(self.name,number)).fetchall()
        conn.close()
        return result if bool(result) else 0


    def user_operation(self,card_id=1,user_name='a',number='1',bonus=0,delete=False):
        ''' if delete==True, delete contact from base \n
        ELSE add user to base'''
        try:
            number=number.replace('+7','8')
            card_id=int(card_id)
            user_name=str(user_name)
        except ValueError as e:
            print(e)
            return -1
        

        
        conn=self._connect()
        cursor=conn.cursor()
        if delete==False:
            try:
                result=cursor.execute("""
                INSERT INTO {}(id,name,phone,bonus)
                VALUES ({},'{}','{}',{})""".format(self.name,card_id,user_name,number,bonus)).fetchall()
            except:
                print('this object is already instantiate')
                conn.close()
                return 0
        else:
            try:
                
                result=cursor.execute("""
                DELETE FROM {} WHERE phone = '{}'""".format(self.name,number)).fetchall()
                conn.commit()
                conn.close()
                
                return result
            except Exception as e:
                
                print(e)
                conn.close()
                return -1

        conn.commit()
        conn.close()
        return user_name

#with open('date.txt','w+') as e:


