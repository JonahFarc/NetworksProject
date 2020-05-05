#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv) {
    // Parsing arguments
    if(argc != 3 && argc != 5) {
        printf("Invalid number of arguments provided.\n");
        return -1;
    }
    int node_id = (int)strtol(argv[1], NULL, 10);
    int destionation_id = (int) strtol(argv[2], NULL, 10);
    char* message = NULL;
    int message_time = -1;
    if(node_id != destionation_id) {
        message = argv[3];
        message_time = (int)strtol(argv[4], NULL, 10);
    }
    printf("Node ID: %d\nReceiver ID: %d\nMessage: %s\nTime:%d\n", node_id, destionation_id, message, message_time);

    // Opening file for writing
    int write_fd, write_flag;
    char write_filename[20];
    sprintf(write_filename, "from%d.txt", node_id);
    write_flag = (O_TRUNC | O_CREAT | O_WRONLY);
    write_fd = open(write_filename, write_flag, 0x1c0);
    if (write_fd < 0 ) {printf("Error opening %s\n", write_filename); exit(1);}

    // Opening file for reading
    int read_fd, read_flag;
    char read_filename[20];
    sprintf(read_filename, "to%d.txt", node_id);
    read_flag = (O_CREAT | O_RDONLY);
    read_fd = open("tempfile", read_flag, 0x1c0);
    if (read_fd < 0 ) {printf("Error opening %s\n", read_filename); exit(1);}

    // Main loop
    int i = 120;
    while(i --> 0) {

        sleep(1);
    }
    /*
     *  initialize variables
     *  open fromX.txt for appending, toX.txt for reading,
     *      and Xreceived for appending.
     *  i = 0
     *  while (i < 120)
     *      read toX.txt
     *      process any new received messages  (i.e.  DATA, HELLO, TC)
     *      if it is time to send the data string
     *          if there is a routing table entry for the destination
     *              send the data message
     *      if i is a multiple of 5 send a hello message
     *      if i is a multiple of 10 send a TC message
     *      remove old entries of the neighbor table if necessary
     *      remove old entries from the TC table if necessary
     *      recalculate the routing table if necessary
     *      i = i + 1;
     *      sleep for 1 second.
     *  end while
     *  close files
     */
    return 0;
}
