#define _CRT_SECURE_NO_WARNINGS 1
#include <unistd.h>
功能:创建一无名管道
	原型
	int pipe(int fd[2]);
   参数
	   fd：文件描述符数组, 其中fd[0]表示读端, fd[1]表示写端
	   返回值 : 成功返回0，失败返回错误代码
	   从键盘读取数据，写入管道，读取管道，写到屏幕
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
	   int main(void)
   {
	   int fds[2];
	   char buf[100];
	   int len;
	   if (pipe(fds) == -1)
		   perror("make pipe"), exit(1);
	   // read from stdin
	   while (fgets(buf, 100, stdin)) {
		   len = strlen(buf);
		   // write into pipe
		   if (write(fds[1], buf, len) != len) {
			   perror("write to pipe");
			   break;
		   }
		   memset(buf, 0x00, sizeof(buf));

		   // read from pipe
		   if ((len = read(fds[0], buf, 100)) == -1) {
			   perror("read from pipe");
			   break;
		   }
		   // write to stdout
		   if (write(1, buf, len) != len) {
			   perror("write to stdout");
			   break;
		   }
	   }
   }
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#define ERR_EXIT(m) \
do \
{ \
    perror(m); \
    exit(EXIT_FAILURE); \
} while(0)
   int main(int argc, char *argv[])
   {
	   int pipefd[2];
	   if (pipe(pipefd) == -1)
		   ERR_EXIT("pipe error");
	   pid_t pid;
	   pid = fork();
	   if (pid == -1)
		   ERR_EXIT("fork error");
	   if (pid == 0) {
		   close(pipefd[0]);
		   write(pipefd[1], "hello", 5);
		   close(pipefd[1]);
		   exit(EXIT_SUCCESS);
	   }
	   比特科技
		   例子1.在minishell中添加管道的实现：
		   close(pipefd[1]);
	   char buf[10] = { 0 };
	   read(pipefd[0], buf, 10);
	   printf("buf=%s\n", buf);
	   return 0;
   }
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# define MAX_CMD 1024
   char command[MAX_CMD];
   int do_face()
   {
	   memset(command, 0x00, MAX_CMD);
	   printf("minishell$ ");
	   fflush(stdout);
	   if (scanf("%[^\n]%*c", command) == 0) {
		   getchar();
		   return -1;
	   }
	   return 0;
   }
   char **do_parse(char *buff) {
	   int argc = 0;
	   static char *argv[32];
	   char *ptr = buff;
	   while (*ptr != '\0') {
		   if (!isspace(*ptr)) {
			   argv[argc++] = ptr;
			   while ((!isspace(*ptr)) && (*ptr) != '\0') {
				   ptr++;
			   }
			   continue;
		   }
		   *ptr = '\0';
		   ptr++;
	   }
	   argv[argc] = NULL;
	   return argv;
   }
   int do_redirect(char *buff) {
	   char *ptr = buff, *file = NULL;
	   int type = 0, fd, redirect_type = -1;
	   while (*ptr != '\0') {
		   if (*ptr == '>') {
			   *ptr++ = '\0';
			   redirect_type++;
			   if (*ptr == '>') {
				   *ptr++ = '\0';
				   redirect_type++;
			   }
			   while (isspace(*ptr)) {
				   ptr++;
			   }
			   file = ptr;
			   while ((!isspace(*ptr)) && *ptr != '\0') {
				   ptr++;
			   }
			   *ptr = '\0';
			   if (redirect_type == 0) {
				   fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0664);
			   }
			   else {
				   fd = open(file, O_CREAT | O_APPEND | O_WRONLY, 0664);
			   }
			   dup2(fd, 1);
		   }
		   ptr++;
	   }
	   return 0;
   }
   int do_command(char *buff) {
	   int pipe_num = 0, i;
	   char *ptr = buff;
	   int pipefd[32][2] = { { -1 } };
	   int pid = -1;
	   pipe_command[pipe_num] = ptr;
	   while (*ptr != '\0') {
		   if (*ptr == '|') {
			   pipe_num++;
			   *ptr++ = '\0';
			   pipe_command[pipe_num] = ptr;
			   continue;
		   }
		   ptr++;
	   }
	   pipe_command[pipe_num + 1] = NULL;
	   return pipe_num;
   }
   int do_pipe(int pipe_num) {
	   int pid = 0, i;
	   int pipefd[10][2] = { { 0 } };
	   char **argv = { NULL };
	   for (i = 0; i <= pipe_num; i++) {
		   pipe(pipefd[i]);
	   }
	   for (i = 0; i <= pipe_num; i++) {
		   pid = fork();
		   if (pid == 0) {
			   do_redirect(pipe_command[i]);
			   argv = do_parse(pipe_command[i]);
			   if (i != 0) {
				   close(pipefd[i][1]);
				   dup2(pipefd[i][0], 0);
			   }
			   if (i != pipe_num) {
				   close(pipefd[i + 1][0]);
				   dup2(pipefd[i + 1][1], 1);
			   }
			   execvp(argv[0], argv);
		   }
		   else {
			   close(pipefd[i][0]);
			   close(pipefd[i][1]);
			   waitpid(pid, NULL, 0);
		   }
	   }
	   return 0;
   }
   int main(int argc, char *argv[])
   {
	   int num = 0;
	   while (1) {
		   if (do_face() < 0)
			   continue;
		   num = do_command(command);
		   do_pipe(num);
	   }
	   return 0;
   }
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#define ERR_EXIT(m) \
do \
{ \
    perror(m); \
    exit(EXIT_FAILURE); \
} while(0)
   int main(int argc, char *argv[])
   {
	   mkfifo("tp", 0644);
	   int infd;
	   infd = open("abc", O_RDONLY);
	   if (infd == -1) ERR_EXIT("open");
	   int outfd;
	   outfd = open("tp", O_WRONLY);
	   if (outfd == -1) ERR_EXIT("open");
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#define ERR_EXIT(m) \
 do \
 { \
 perror(m); \
 exit(EXIT_FAILURE); \
 } while(0)

	   int main(int argc, char *argv[])
	   {
		   int outfd;
		   outfd = open("abc.bak", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		   if (outfd == -1) ERR_EXIT("open");

		   int infd;
		   infd = open("tp", O_RDONLY);
		   if (outfd == -1)
			   ERR_EXIT("open");
		   char buf[1024];
		   int n;
		   while ((n = read(infd, buf, 1024))>0)
		   {
			   write(outfd, buf, n);
		   }
		   close(infd);
		   close(outfd);
		   unlink("tp");
		   return 0;
	   }