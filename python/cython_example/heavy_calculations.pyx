import time


def grad_J(x, u):
    return 4*x + 2*u + 3., 2*x + 2*u + 5.;


def some_funtion(x, u):
    z = 2 * x**2 + u**2 + 2 * x * u + 3 * x + 5 * u - 10.
    return z

def start():
    print("Start!")
    start_time = time.time()
    gamma = 0.0001
    x, u = 0, 0
    prev_x, prev_u = 5., 2.;
    g = grad_J(prev_x, prev_u)
    step = 0
    while sum(g) != 0:
        x = prev_x - gamma * g[0]
        u = prev_u - gamma * g[1]
        prev_x, prev_u = x, u
        g = grad_J(prev_x, prev_u)
        step += 1
        # print('Gradient: {0:<{width}}{1:<{width}}'.format(g[0],g[1], width=20))

    seconds = time.time() - start_time
    print("Complete in {0} stepts for {1} seconds!".format(step, seconds))

start()
