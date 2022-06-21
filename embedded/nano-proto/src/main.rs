#![no_std]
#![no_main]
#![feature(core_intrinsics)]
#![allow(dead_code)]
#![allow(non_snake_case)]

use core::{panic::PanicInfo};
// use core::intrinsics::volatile_store;
mod atmega328p; use atmega328p::*;
mod utils; use utils::*;

#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
    loop {}
}

#[arduino_hal::entry]
fn main() -> ! {
    // let dp = arduino_hal::Peripherals::take().unwrap();
    // let pins = arduino_hal::pins!(dp);
    
    // // Digital pin 13 is also connected to an onboard LED marked "L"
    // let mut led = pins.d2.into_output();
    // led.set_low();

    let bit:u8 = 2;
    unsafe {
        set_reg_bit(DDRD, bit, true); // set as output

        loop {
            set_reg_bit(PORTD, bit, true); // set high
            arduino_hal::delay_ms(500);            
            set_reg_bit(PORTD, bit, false); // set low
            arduino_hal::delay_ms(500);
        }
    }
}