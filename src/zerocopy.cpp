#include <fcntl.h>
#include <sys/mman.h>
#include <sys/sendfile.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
    // 打开文件
    int fd = open("myfile.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // 获取文件大小
    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        perror("fstat");
        close(fd);
        return 1;
    }

    // 内存映射文件
    void* addr = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return 1;
    }

    // 创建socket
    int out_fd = socket(AF_INET, SOCK_STREAM, 0);
    // 假设out_fd已经连接到了网络

    // 使用sendfile发送数据
    if (sendfile(out_fd, fd, NULL, sb.st_size) == -1) {
        perror("sendfile");
    }

    // 清理
    munmap(addr, sb.st_size);
    close(fd);
    close(out_fd);

    return 0;
}