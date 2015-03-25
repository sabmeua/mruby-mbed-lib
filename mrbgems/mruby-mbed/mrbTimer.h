#ifdef __cplusplus
extern "C" {
#endif

void *newTimer();
void delTimer(void *ptr);
void startTimer(void *ptr);
void stopTimer(void *ptr);
void resetTimer(void *ptr);
float readTimer(void *ptr);
int readMSTimer(void *ptr);
int readUSTimer(void *ptr);

#ifdef __cplusplus
}
#endif


