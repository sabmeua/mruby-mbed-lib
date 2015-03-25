#ifdef __cplusplus
extern "C" {
#endif

void *newDigitalOut(int pin);
void delDigitalOut(void *object);
void writeDigitalOut(void *object, int value);
int readDigitalOut(void *object);

#ifdef __cplusplus
}
#endif
