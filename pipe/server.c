#include "client.h"
#include <ctype.h>
//������
int main(){
	int server_fifo_fd,client_fifo_fd;
	struct data_to_pass_st my_data;
	int read_res;
	int res;
	char client_fifo[256];
	char *temp_char_ptr;
		if(access(SERVER_FIFO_NAME,F_OK) == -1){
		res = mkfifo(SERVER_FIFO_NAME,0777);
		if(res != 0){
				char *mesg = (char *)strerror(errno);
			fprintf(stderr,"Mesg:%s\n",mesg);
				exit(EXIT_FAILURE);
		}
	}
	server_fifo_fd = open(SERVER_FIFO_NAME,O_RDONLY);
	if(server_fifo_fd == -1){
		fprintf(stderr,"server fifo failure\n");
		exit(EXIT_FAILURE);
	}
	//sleep(10);//�ÿͻ���д
	do{
		read_res = read(server_fifo_fd,&my_data,sizeof(my_data));
		if(read_res>0){
			temp_char_ptr = my_data.some_data;
		
		while(*temp_char_ptr){
			*temp_char_ptr = toupper(*temp_char_ptr);
			temp_char_ptr++;
		}
		sprintf(client_fifo,CLIENT_FIFO_NAME,my_data.client_pid);
		client_fifo_fd = open(client_fifo,O_WRONLY);
		if(client_fifo_fd != -1){
		write(client_fifo_fd,&my_data,sizeof(my_data));
        close(client_fifo_fd);		
		}
		
		
		}
	}while(read_res>0);
		close(server_fifo_fd);
		//ɾ���ļ�(���ļ�û�н��̶�ȡ������·��򲻻�ɾ��ֻ��ɾ���Լ��������ڵ����ӽڵ�)
		unlink(SERVER_FIFO_NAME);
		exit(EXIT_SUCCESS);
}