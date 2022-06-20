#![no_std]
#![no_main]

use core::panic::PanicInfo;
use ruduino::cores::current::PORTB;

#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
    loop {}
}


#[arduino_hal::entry]
fn main() -> ! {
    // let dp = arduino_hal::Peripherals::take().unwrap();
    // let pins = arduino_hal::pins!(dp);
    
    // // Digital pin 13 is also connected to an onboard LED marked "L"
    // let mut led = pins.d13.into_output();
    // led.set_low();
    unsafe {

        loop {
            // led.toggle();
            // arduino_hal::delay_ms(500);
            // led.toggle();
            // arduino_hal::delay_ms(500);
        }
    }
}


// #include <avr/io.h>
// #include <util/delay.h>

// #define MS_DELAY 3000

// int main (void) {
//     /*Set to one the fifth bit of DDRB to one
//     **Set digital pin 13 to output mode */
//     DDRB |= _BV(DDB5);

//     while(1) {
//         /*Set to one the fifth bit of PORTB to one
//         **Set to HIGH the pin 13 */
//         PORTB |= _BV(PORTB5);

//         /*Wait 3000 ms */
//         _delay_ms(MS_DELAY);

//         /*Set to zero the fifth bit of PORTB
//         **Set to LOW the pin 13 */
//         PORTB &= ~_BV(PORTB5);

//         /*Wait 3000 ms */
//         _delay_ms(MS_DELAY);
//     }
// }