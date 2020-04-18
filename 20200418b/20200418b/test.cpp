//#define _CRT_SECURE_NO_WARNINGS 1
//#include <sys/wait.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <errno.h>
//int main(void)
//{
//	pid_t pid;
//	if ((pid = fork()) == -1)
//		perror("fork"), exit(1);
//	if (pid == 0)
//	{
//		sleep(20);
//		exit(10);
//	}
//	else 
//	{
//		int st;
//		int ret = wait(&st);
//
//		if (ret > 0 && (st & 0X7F) == 0) { // 正常退出
//			printf("child exit code:%d\n", (st >> 8) & 0XFF);
//		}
//		else if (ret > 0) { // 异常退出
//			printf("sig code : %d\n", st & 0X7F);
//		}
//	}
//}
//int main()
//{
//	pid_t pid;
//	pid = fork();
//	if (pid < 0) 
//	{
//		printf("%s fork error\n", __FUNCTION__);
//		return 1;
//	}
//	else if (pid == 0) 
//	{ //child
//		printf("child is run, pid is : %d\n", getpid());
//		sleep(5);
//		exit(257);
//	}
//	else 
//	{
//		int status = 0;
//		pid_t ret = waitpid(-1, &status, 0);//阻塞式等待，等待5S
//		printf("this is test for wait\n");
//		if (WIFEXITED(status) && ret == pid)
//		{
//			printf("wait child 5s success, child return code is 
//				:%d.\n",WEXITSTATUS(status));
//		}
//		else
//		{
//			printf("wait child failed, return.\n");
//			return 1;
//		}
//	}
//	return 0;
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#define MAX_CMD 1024
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
char **do_parse(char *buff)
{
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
int do_exec(char *buff)
{
	char **argv = { NULL };
	int pid = fork();
	if (pid == 0) {
		argv = do_parse(buff);
		if (argv[0] == NULL) {
				exit(-1);
		}
		execvp(argv[0], argv);
	}
	else {
		waitpid(pid, NULL, 0);
	}
	return 0;
}
int main(int argc, char *argv[])
{
	while (1) {
		if (do_face() < 0)
			continue;
		do_exec(command);
	}
	return 0;
}