#![no_std]
#![no_main]
#![feature(core_intrinsics)]
#![allow(dead_code)]

use core::{panic::PanicInfo};
use core::intrinsics::volatile_store;
mod atmega328p;
use atmega328p::*;

#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
    loop {}
}


fn LS1(bit: u8) -> u8 {
    1 << (bit)
}

fn LS0(bit:u8) -> u8 {
    0 << (bit)
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
        volatile_store(DDRD,*DDRD | LS1(bit)); // pin 13 is output
        volatile_store(PORTD,*PORTD | LS1(bit));

        loop {
            volatile_store(PORTD,*PORTD | LS1(bit));
            arduino_hal::delay_ms(1000);            
            volatile_store(PORTD,*PORTD & LS0(bit));
            arduino_hal::delay_ms(1000);
        }
    }
}