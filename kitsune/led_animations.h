#ifndef LED_ANIMATIONS_H
#define LED_ANIMATIONS_H
#ifdef __cplusplus
extern "C" {
#endif

//call to stop all animations
void stop_led_animation(void);
int Cmd_led_animate(int argc, char *argv[]);

//custom animations
void play_led_animation_pulse(void);
void play_led_trippy(void);

#ifdef __cplusplus
}
#endif
#endif
