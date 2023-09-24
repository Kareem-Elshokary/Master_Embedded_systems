
Memory Configuration

Name             Origin             Length             Attributes
flash            0x00000000         0x20000000         xr
sram             0x20000000         0x20000000         xrw
*default*        0x00000000         0xffffffff

Linker script and memory map


.text           0x00000000      0x1a4
 *(.vectors*)
 .vectors       0x00000000       0x50 startup.o
 *(.text*)
 .text          0x00000050       0x3a main.o
                0x00000050                main
 *fill*         0x0000008a        0x2 
 .text          0x0000008c       0x2c Pressure_sensor.o
                0x0000008c                Check_P_val
 .text          0x000000b8       0xc4 Driver.o
                0x000000b8                Delay
                0x000000da                getPressureVal
                0x000000f0                Set_Alarm_actuator
                0x0000012c                GPIO_INITIALIZATION
 .text          0x0000017c       0x1c Alarm.o
                0x0000017c                Alarm_On
                0x0000018a                Alarm_Off
 .text          0x00000198        0xc startup.o
 *(.rodata)
                0x000001a4                _E_text = .

.glue_7         0x000001a4        0x0
 .glue_7        0x000001a4        0x0 linker stubs

.glue_7t        0x000001a4        0x0
 .glue_7t       0x000001a4        0x0 linker stubs

.vfp11_veneer   0x000001a4        0x0
 .vfp11_veneer  0x000001a4        0x0 linker stubs

.v4_bx          0x000001a4        0x0
 .v4_bx         0x000001a4        0x0 linker stubs

.iplt           0x000001a4        0x0
 .iplt          0x000001a4        0x0 main.o

.rel.dyn        0x000001a4        0x0
 .rel.iplt      0x000001a4        0x0 main.o

.data           0x20000000        0x8 load address 0x000001a4
                0x20000000                _S_DATA = .
 *(.data)
 .data          0x20000000        0x4 main.o
                0x20000000                Threshold
 .data          0x20000004        0x4 Pressure_sensor.o
 .data          0x20000008        0x0 Driver.o
 .data          0x20000008        0x0 Alarm.o
 .data          0x20000008        0x0 startup.o
                0x20000008                . = ALIGN (0x4)
                0x20000008                _E_DATA = .

.igot.plt       0x20000008        0x0 load address 0x000001ac
 .igot.plt      0x20000008        0x0 main.o

.bss            0x20000008        0x8 load address 0x000001ac
                0x20000008                _S_bss = .
 *(.bss*)
 .bss           0x20000008        0x4 main.o
                0x20000008                P_val
 .bss           0x2000000c        0x4 Pressure_sensor.o
 .bss           0x20000010        0x0 Driver.o
 .bss           0x20000010        0x0 Alarm.o
 .bss           0x20000010        0x0 startup.o
                0x20000010                _E_bss = .
LOAD main.o
LOAD Pressure_sensor.o
LOAD Driver.o
LOAD Alarm.o
LOAD startup.o
OUTPUT(Pressure_Detection.elf elf32-littlearm)
LOAD linker stubs

.debug_info     0x00000000      0x36d
 .debug_info    0x00000000       0xd5 main.o
 .debug_info    0x000000d5       0xe1 Pressure_sensor.o
 .debug_info    0x000001b6      0x112 Driver.o
 .debug_info    0x000002c8       0x7f Alarm.o
 .debug_info    0x00000347       0x26 startup.o

.debug_abbrev   0x00000000      0x247
 .debug_abbrev  0x00000000       0x7c main.o
 .debug_abbrev  0x0000007c       0x8b Pressure_sensor.o
 .debug_abbrev  0x00000107       0xc3 Driver.o
 .debug_abbrev  0x000001ca       0x69 Alarm.o
 .debug_abbrev  0x00000233       0x14 startup.o

.debug_loc      0x00000000      0x1f0
 .debug_loc     0x00000000       0x2c main.o
 .debug_loc     0x0000002c       0x2c Pressure_sensor.o
 .debug_loc     0x00000058      0x140 Driver.o
 .debug_loc     0x00000198       0x58 Alarm.o

.debug_aranges  0x00000000       0xa0
 .debug_aranges
                0x00000000       0x20 main.o
 .debug_aranges
                0x00000020       0x20 Pressure_sensor.o
 .debug_aranges
                0x00000040       0x20 Driver.o
 .debug_aranges
                0x00000060       0x20 Alarm.o
 .debug_aranges
                0x00000080       0x20 startup.o

.debug_line     0x00000000      0x275
 .debug_line    0x00000000       0x6a main.o
 .debug_line    0x0000006a       0x69 Pressure_sensor.o
 .debug_line    0x000000d3      0x121 Driver.o
 .debug_line    0x000001f4       0x46 Alarm.o
 .debug_line    0x0000023a       0x3b startup.o

.debug_str      0x00000000      0x1d5
 .debug_str     0x00000000      0x125 main.o
                                0x164 (size before relaxing)
 .debug_str     0x00000125       0x26 Pressure_sensor.o
                                0x17e (size before relaxing)
 .debug_str     0x0000014b       0x57 Driver.o
                                0x1a3 (size before relaxing)
 .debug_str     0x000001a2       0x1b Alarm.o
                                 0xdc (size before relaxing)
 .debug_str     0x000001bd       0x18 startup.o
                                 0x62 (size before relaxing)

.comment        0x00000000       0x49
 .comment       0x00000000       0x49 main.o
                                 0x4a (size before relaxing)
 .comment       0x00000049       0x4a Pressure_sensor.o
 .comment       0x00000049       0x4a Driver.o
 .comment       0x00000049       0x4a Alarm.o

.ARM.attributes
                0x00000000       0x2b
 .ARM.attributes
                0x00000000       0x2d main.o
 .ARM.attributes
                0x0000002d       0x2d Pressure_sensor.o
 .ARM.attributes
                0x0000005a       0x2d Driver.o
 .ARM.attributes
                0x00000087       0x2d Alarm.o
 .ARM.attributes
                0x000000b4       0x21 startup.o

.debug_frame    0x00000000      0x140
 .debug_frame   0x00000000       0x2c main.o
 .debug_frame   0x0000002c       0x2c Pressure_sensor.o
 .debug_frame   0x00000058       0xa0 Driver.o
 .debug_frame   0x000000f8       0x48 Alarm.o
