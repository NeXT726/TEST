
import random
 
 
def get_conflict_num(status):
	conflict_num = 0
	for c1 in range(0, 7):
		for c2 in range(c1+1, 8):
			if (status[c1] == status[c2]) or ((c2 - c1) == abs(status[c1] - status[c2])) :
				conflict_num += 1
	return conflict_num
 
 
 
def get_best_neighbor(status):
	min_status = status
	for c in range(0,8):
		for r in range(0, 8):
			new_status = status[:]
			if status[c] != r:
				new_status[c] = r
				if get_conflict_num(new_status) < get_conflict_num(min_status): 
					min_status = new_status 
				elif get_conflict_num(new_status) == get_conflict_num(min_status) and get_conflict_num(new_status) != get_conflict_num(status): 
					min_status = new_status
	return min_status  
 
status = [0, 0, 0, 0, 0, 0, 0, 0] 
for c in range(0, 8):
	r = random.randint(0, 7)
	status[c] = r
	print("Status: ", status, "Conflict Num: ", get_conflict_num(status)) 
while get_conflict_num(status) > 0 :
    new_status = get_best_neighbor(status)
    if new_status == status:
        print("Status: ", status, "Conflict Num: ", get_conflict_num(status)) 
        print("Fail!")
        break
    status = new_status
    print("Status: ", status, "Conflict Num: ", get_conflict_num(status)) 
    if get_conflict_num(status) == 0:
        print("Success!")