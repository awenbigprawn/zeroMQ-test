//  Hello World client
#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <ctime>

int main (void)
{
    printf ("Connecting to hello world server…\n");
    clock_t start = clock();
    void *context = zmq_ctx_new ();
    void *requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "tcp://localhost:5555");
    clock_t init_finish = clock();

    int request_nbr;
    for (request_nbr = 0; request_nbr != 100; request_nbr++) {
        char buffer [10];
        printf ("Sending Hello %d…\n", request_nbr);
        clock_t start_req = clock();
        zmq_send (requester, "Hello", 5, 0);
        zmq_recv (requester, buffer, 10, 0);
        clock_t receive_rep = clock();
        printf ("Received World %d\n", request_nbr);
        printf ("time_usage = %f\n", double(receive_rep-start_req)/CLOCKS_PER_SEC);
    }
    zmq_close (requester);
    zmq_ctx_destroy (context);
    return 0;
}
