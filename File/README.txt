This directory contains all the file operation in C

Typical File operation:
===================================================
01. FILE *fopen(const char *path, 
                const char *mode);

02. int fclose(FILE *fp);

03. int fseek(FILE *stream, 
              long offset, 
              int whence);

04. long ftell(FILE *stream);

05. int fgetc(FILE *stream);

06. char *fgets(char *s, 
                int size, 
                FILE *stream);

07. int getchar(void);

08. char *gets(char *s);

09. size_t fwrite(const void *ptr, 
                  size_t size, 
                  size_t nmemb,
                  FILE *stream);

10. size_t fread(void *ptr, 
                 size_t size, 
                 size_t nmemb, 
                 FILE *stream);

11. int ftruncate(int fd, 
                  off_t length); 

12. void rewind(FILE *stream);

13. int fprintf(FILE *stream, 
                const char *format, ...);
