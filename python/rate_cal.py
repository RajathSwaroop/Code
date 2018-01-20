

inp_str = "00:01:07,400-234-090\n00:05:01,701-080-080\n00:05:00,400-234-090"

dur = []
time_st = []
num = []
price = 0
new_price = 0

def data_collect():
	#global dur, num	
	line = inp_str.split("\n")
	for l in line:
		sub_line = str(l).split(",")
		print(sub_line)
		for i in range(len(sub_line)):
		#print(i)
			if i%2 == 0:		
				dur.append(str(sub_line[i]))
	
			else:
				num.append(str(sub_line[i]))

	for i in range(len(dur)):	
		hms = str(dur[i]).split(":")
		h = float(hms[0])*3600.0
		m = float(hms[1])*60.0
		s = float(hms[2])
		time_st.append(h+m+s)
		print(h+m+s)

def allign_data():
	for i in range(len(num)):
		for j in range(len(num)):
			if num[i] == num[j] and i!=j:	
				time_st[i] = time_st[i]+time_st[j]
				time_st[j] = 0	
				num[j] = 0

def fare_elm():
	for i in range(len(time_st)-1):
		if float(time_st[i]) < float(time_st[i+1]):
			temp = time_st[i]
			time_st[i] = time_st[i+1]
			time_st[i+1] = temp
			temp = num[i]
			num[i] = num[i+1]
			num[i+1] = temp			
	
	num[0] = 0
	time_st[0] = 0
	

def fare_cal():
	global price
	for i in range(len(time_st)):
		if float(str(time_st[i])) > 299:
			if float(str(time_st[i]))%60 != 0:		
				new_price = ((float(str(time_st[i]))/60) + 1)*150
			else:
				new_price = ((float(str(time_st[i]))/60)*150)
			

		else:
			new_price = float(time_st[i]) * 1.5
			
		price = price + new_price



data_collect()
print(time_st)
allign_data()
print(time_st)
fare_elm()
print(time_st)
fare_cal()

print(time_st)
print(dur)
print(num)
print(price)
#print(str(num[0])==str(num[2]))
#print(str(num[1]))
#print(str(num[2]))
