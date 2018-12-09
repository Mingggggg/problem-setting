import sys, re

n_line = sys.stdin.readline()

if re.match('^([1-9]\d*) ([1-9]\d*) ([1-9]\d*)$', n_line) == None:
	sys.exit(1) # invalid n & m

l = n_line.split(" ")
n = int(l[0])
m = int(l[1])
k = int(l[2])
if (not (n <= 100 and m <= 100 and k <= 1000)):
	#print("1")
	sys.exit(1) # invalid n & m

for i in range(n):
	nums_line = sys.stdin.readline()
# Here we match n integers. An integer must not have leading zero.
	if re.match('^(0|[1-9]\d*)( (0|[1-9]\d*)){%d}$' % (m-1), nums_line) == None:
		#print("2")
		sys.exit(2) # invalid distances

	nums = [int(x) for x in nums_line.strip().split(' ')]
	if i == 0:
		if nums[0] != 0:
			#print("3")
			sys.exit(3) # distance out of range
		nums = nums[1:]
	if max(nums) > 1e9 or min(nums) < 1:
		#print("3")
		sys.exit(3) # distances out of range

for i in range(n):
	nums_line = sys.stdin.readline()
# Here we match n integers. An integer must not have leading zero.
	if re.match('^(0|[1-9]\d*)( (0|[1-9]\d*)){%d}$' % (m-1), nums_line) == None:
		#print("4")
		sys.exit(4) # invalid p

	nums = [int(x) for x in nums_line.strip().split(' ')]
	if i == 0:
		if nums[0] != 0:
			#print("3")
			sys.exit(3) # distance out of range
		nums = nums[1:]
	if max(nums) > 1000 or min(nums) < 1:
		#print("5")
		sys.exit(5) # p out of range
# an input validator must exit with code 42 to for success
if (sys.stdin.read() != ''):
	sys.exit(6) # junk at the end
# print("42")
sys.exit(42)
