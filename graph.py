import numpy as np
import sys
import matplotlib.pyplot as plt
import mpl_toolkits.mplot3d.axes3d as p3
import matplotlib.animation as animation

def Gen_RandLine(length, dims=2):
    """
    Create a line using a random walk algorithm

    length is the number of points for the line.
    dims is the number of dimensions the line has.
    """
    lineData = np.empty((dims, length))
    lineData[:, 0] = np.random.rand(dims)
    for index in range(1, length):
        # scaling the random numbers by 0.1 so
        # movement is small compared to position.
        # subtraction by 0.5 is to change the range to [-0.5, 0.5]
        # to allow a line to move backwards.
        step = ((np.random.rand(dims) - 0.5) * 0.1)
        lineData[:, index] = lineData[:, index - 1] + step

    return lineData

def get_data(bodies=3, dim=3, iterations=11):
    tmp = [[],[],[]]
    return_me = np.empty((bodies,dim, iterations))#[[],[],[]]
    # print(return_me.shape)
    #return_me = return_me.tolist()
    c = 0
    with open("write_data.txt", 'r') as f:
        for line in f:
            if line[:9] == "iteration":
                c = 0
            elif line[0] == "(":
                split_line = line[1:-2].split(', ')
                tmp[c].append([str(i) for i in split_line]) 
                c+=1
    print("TEMP")
    tmp = np.array(tmp)
    print(np.array(tmp).shape)
    print(np.array(tmp))
    # lineData = np.empty((dim, iterations))
    # print(lineData)
    # print("")
    # lineData[:, 2] = 10
    # print(lineData)
    # return_me = return_me.tolist()
    # print(np.array(tmp).reshape(3,11,3).shape)
    # print(np.array(tmp))
    # return_me[:]

    # return_me[:,] = tmp[:,]
    for j in range(iterations):
        return_me[:, :, j] = tmp[:, j, :]
            # return_me[][][] = tmp[][][]
            # return_me[][][] = tmp[][][]

    print("RETURN")
    print(return_me)


    return return_me

def update_lines(num, dataLines, lines):
    for line, data in zip(lines, dataLines):
        # NOTE: there is no .set_data() for 3 dim data...
        line.set_data(data[0:2, :num])
        line.set_3d_properties(data[2, :num])
    return lines

temp = [Gen_RandLine(25, 3) for index in range(50)]
# print("desired shape: [[lines],[x,y,z],[itertions]]")

# Attaching 3D axis to the figure
fig = plt.figure()
ax = p3.Axes3D(fig)

# read data from file
data = get_data()

# Creating "iterations" line objects.
# NOTE: Can't pass empty arrays into 3d version of plot()
lines = []
# print(np.array(data))
lines = [ax.plot(dat[0, 0:1], dat[1, 0:1], dat[2, 0:1])[0] for dat in data]
# Setting the axes properties
ax.set_xlim3d([0.0, 30000000.0])
ax.set_xlabel('X')

ax.set_ylim3d([0.0, 30000000.0])
ax.set_ylabel('Y')

ax.set_zlim3d([0.0, 30000000.0])
ax.set_zlabel('Z')

ax.set_title('3D Test')

# Creating the Animation object
line_ani = animation.FuncAnimation(fig, update_lines, 25, fargs=(data, lines),
                                   interval=50, blit=False)

plt.show()