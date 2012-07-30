/* ���: usbconfig.h
 * ������: ������� AVR USB
 * �����: Christian Starkjohann
 * �������: microsin.ru  
 * ���� ��������: 2005-04-01
 * ���������: 4
 * Copyright: (c) 2005 by OBJECTIVE DEVELOPMENT Software GmbH
 * ��������: GNU GPL v2 (��. License.txt) ��� ������������� (CommercialLicense.txt) 
 * �������: $Id: usbconfig-prototype.h 600 2008-05-13 10:34:56Z cs $
 */

#ifndef __usbconfig_h_included__
#define __usbconfig_h_included__

/*
�������� ��������:
���� ���� �������� �������� ������������ (�� ���������� �������������) ��� USB
��������. �� ������������� AVR-USB ��� USB D+, ������������� �� ���� D ��� 2 
(������� ����� ��������� ������� ����������� ���������� 0 ��� ������ 
�����������������) � USB D- �� ���� D ��� 4. �� ������ ������������ ��� �������
�� ����� ������ ����, ���� D+ �������� ����������� � INT0 (��� � ����� ������ 
���������� ���������� ��� �������, ��� ��� ����� ��������� ������� ����������,
��. ������ � ����� ����� �����).
+ ��� �������� ������ ������������ ����� usbconfig.h, ���������� ���� ���� � �������
+ � ����������� ������ firmware ������� � ������������ ��� � "usbconfig.h".
+ ����� �������������� ���� �������� ����� ������������.
*/

/* ---------------------------- ������������ ������ ---------------------------- */

#define USB_CFG_IOPORTNAME      D
/* ��� ����, �� ������� ���������� ���� USB. ����� ��������������� ��� �
 * "B", ����� �������������� �������� PORTB, PINB � DDRB.
 */
#define USB_CFG_DMINUS_BIT      4
/* ��� ����� ���� ����� USB_CFG_IOPORTNAME, ���� ���������� ����� USB D-.
 * ��� ����� ���� ����� ��� �����.
 */
#define USB_CFG_DPLUS_BIT       2
/* ��� ����� ���� ����� USB_CFG_IOPORTNAME, ���� ���������� ����� USB D+.
 * ��� ����� ���� ����� ��� �����. ���������� ������� �� ��������, ��� D+ 
 * ������ ���� ����� ����������� �� ����� ���������� INT0! [�� ������ ����� 
 * ������������ ������ ����������, ��. ������ "�������������� �������� MCU" 
 * �����, ��� �� ������ ������������ �� ���������� ������ D-, ��� ��� ���������
 * ���� �� ����������� ����������� USB_COUNT_SOF. ���� �� ����������� D- ���
 * ����������, USB ���������� ����� ����� ����������� �� �������� SOF (Start-Of-Frame)
 * ������ �����������.]
 */
#define F_CPU 12000000UL    // 16MHz clock speed

#define USB_CFG_CLOCK_KHZ       (F_CPU/1000)
/* �������� ������� AVR � ���. ���������� �������� 12000, 15000, 16000, 16500
 * � 20000. ������ ���� 16.5 ��� �� ������� ����������� ��������� � ����������������,
 * ��� ��������� �������� +/- 1% �� ����������� �������� �������. ��� ������ �������
 * ������� �������� 2000 ppm � ������������� ������������� ���������!
 * ���� �� �������, �� �� ��������� ������������ ������� 12 ���
 */

/* ----------------------- �������������� Hardware Config ------------------------ */

/* #define USB_CFG_PULLUP_IOPORTNAME   D */
/* ���� �� ������������ 1.5k pullup �������� �� D- � ����� ����� ������ V+, 
    �� ������ ������������ � ����������� ���������� �� firmware ����� ������
    ������� usbDeviceConnect() � usbDeviceDisconnect() (��. usbdrv.h).
    ��� ��������� ������ ����, � �������� ��������� pullup ��������.
 */
/* #define USB_CFG_PULLUP_BIT          4 */
/* ��� ��������� ���������� ����� ���� ����� � USB_CFG_PULLUP_IOPORTNAME (��������
    �����) ���� ��������� 1.5k pullup ��������. ��. ��������, ��������� �����.
 */ 
 
/* -------------- Functional Range (�������������� ��������) ---------------------------- */ 

#define USB_CFG_HAVE_INTRIN_ENDPOINT    1
/* ������� ����� 1, ���� �� ������ �������������� ������ � ����� ��������� ������� 
    (endpoints): default control endpoint 0 � interrupt-in endpoint (����� ������ 
    endpoint �����).
 */ 
#define USB_CFG_HAVE_INTRIN_ENDPOINT3   0
/* ������� ����� 1, ���� �� ������ �������������� ������ � ����� ��������� ������� 
    (endpoints): default control endpoint 0 � interrupt-in endpoint 3 (��� �����,
    ������������������ �����) � catch-all default interrupt-in endpoint ��� �������
    �����. �� ������ ����� ������ USB_CFG_HAVE_INTRIN_ENDPOINT � 1, ���� ���������� 
    #define USB_CFG_HAVE_INTRIN_ENDPOINT3 1.
 */
#define USB_CFG_EP3_NUMBER              3
/* ���� ��� ���������� �������� ����� (endpoint) 3 ������������, ����� ������ 
    ���������������� ����� ������ ����� �������� ����� (�� ����������� 0) � ���� macro. 
    ���� �� ������, �� �� ��������� 3.
 */
/* #define USB_INITIAL_DATATOKEN           USBPID_DATA1 */
/* Macro, �������� ����� ���������� ������� ������ (startup condition) ��� ������������ 
    ������ (data toggling) � ������ �������� ����� interrupt/bulk 1 � 3. �� ��������� USBPID_DATA1.
    ��������� ����� ������������� ����� ��������� ����� ������, ������ ����� ������������ 
    ��������������� ��������� � ���� ������������!
 */
#define USB_CFG_IMPLEMENT_HALT          0
/* ������� ����� 1, ���� �� ������ ����� ����������� ����������� ENDPOINT_HALT
    ��� endpoint 1 (interrupt endpoint). �������� �� ��, ��� ��� ��� ����������� ����� �� ������������,
    ��� ��������� �� ���������. �� ����� ��� ����� � ������������ ������ ��� 
    ��� ������� ����������� ��������� ���.
 */
#define USB_CFG_INTR_POLL_INTERVAL      100
/* ���� �� �������������� ������ � endpoint 1 (interrupt-in), �� ����� ��������
    �������� ������ (poll interval). �������� ������� � ������������ � �� ������ ���� ������ 10 ms
    ��� ��������������� ���������.
 */
#define USB_CFG_IS_SELF_POWERED         0
/* ������� ����� 1 ���� ���������� ����� ����������� �������� �������. ��������� � 0 �������������
    ����������, ����������� �� ���� USB.
 */
#define USB_CFG_MAX_BUS_POWER           50
/* ���������� ��� ���������� �� max �������� ����������� �������� ������ ���������� �� ���� USB.
    �������� ������� � �����������. [��� ����� �������� ������������ �� 2 ��������� ������������ 
    ��������� ����������������� USB ��������� ��������� � �������� 2 ��.]
 */
#define USB_CFG_IMPLEMENT_FN_WRITE      1
/* ������� ����� 1, ���� �� ������, ����� ������� usbFunctionWrite() ���������� ��� ������� control-out. 
    ������� 0 ���� ��� ��� �� �����, ��� �������� ���������� ��������� ����.
 */
#define USB_CFG_IMPLEMENT_FN_READ       1
/* ������� 1 ���� ��� ����� ���������� ����������� ������� ������, ������� ������������ 
    "�� ����" ��� ������ usbFunctionRead(). ���� ��� ����� ������ ��������� ������
    �� ������������ ������, ������� 0 � ����������� ������ �� usbFunctionSetup(). 
    ��� ��������� ��������� ���������� ����.
 */
#define USB_CFG_IMPLEMENT_FN_WRITEOUT   0
/* ������� 1 ���� �� ������ ������������ interrupt-out (��� bulk out) endpoints.
    �� ������ ����������� ������� usbFunctionWriteOut(), ������� ��������� ���
    interrupt/bulk ������, ������������ � ����� endpoint, �������� �� 0. ����� endpoint
    ����� ����� � 'usbRxToken'.
 */
#define USB_CFG_HAVE_FLOWCONTROL        0
/* ������� 1, ���� �� ������ ����������� ���������� ������� (flowcontrol) ����� ������ USB. 
    ��. �������� ������� usbDisableAllRequests() � usbEnableAllRequests() � usbdrv.h.
 */
#define USB_CFG_LONG_TRANSFERS          0
/* ������� 1, ���� �� ������ ����������/��������� ����� �������� ����� 254 ����
    � ��������� control-in ��� control-out ��������. �������� ��������, ��� ��� �����������
    ����������� ������ ��������.
 */
/* #define USB_RX_USER_HOOK(data, len)     if(usbRxToken == (uchar)USBPID_SETUP) blinkLED(); */
/* ���� macro �������� ������ (hook), ���� �� ������ ������� ����� ��������������. ���� ������ �����,
    �� ����������� � ������ ��������� ������������ ���������. ���� �� "�����" (����������) 
    ��������� � �� ������ �������� ����������� ��������� �� ���������, �������� ������� ������� 
    ����� ����� ��������. ���� �� ��������� ���������� ��������������� ����� One possible application
    (����� �������) - ������� LED ��� ������ ������.
 */
/* #define USB_RESET_HOOK(resetStarts)     if(!resetStarts){hadUsbReset();} */
/* ���� macro �������� ����� ��� ��������� ������� USB RESET. ���� �������� 
   ���������� ��������� RESET ���� start, ���� end.
 */
/* #define USB_SET_ADDRESS_HOOK()              hadAddressAssigned(); */
/* ���� macro (���� �����) ����������� ����� ������ ������ USB SET_ADDRESS.
 */
#define USB_COUNT_SOF                   0
/* ������� ����� 1, ���� ��� ����� ���������� ���������� "usbSofCount", � �������
    �������������� ������ SOF. ��� ����������� ������� ����������� �����������
    ���������� � D- ������ D+.
 */
#define USB_CFG_HAVE_MEASURE_FRAME_LENGTH   0
/* ������� ����� 1, ���� ��� ����� ������� usbMeasureFrameLength() - ����� ��� ��������������.
    ��� ������� ����� �������������� ��� ���������� ���������� RC ���������������� AVR.
 */

/* -------------------------- Device Description --------------------------- */

#define  USB_CFG_VENDOR_ID       0xc0, 0x16
/* USB ������ ID ��� ����������, ������� ���� ���� ������. ���� �� ���������������� ���� 
    ����������� Vendor ID, ������� ��� �����. � ��������� ������ ����������� ���� �� 
    �������� ��������������� ��� VID/PID obdev. ���������� ������� USBID-License.txt!
 * + ���� ������ ���������� ����� ���� VID/PID �� obdev: 0x16c0/0x5dc.
 * + ����������� ��� ���� VID/PID ������ ���� �� ��������� ����� �����!
 */
#define  USB_CFG_DEVICE_ID       0xdf, 0x05
/* ��� ID ��������, ������� ���� ���� ������. �� ���������������� � ��������� 
    vendor ID. ���� �� ���������������� ���� ����������� VID �� usb.org,
    ��� ���� ����������� ��������� �� PID �� ����-������ ���, ������� ��� �����. 
    ����� ����������� ��������������� obdev �������� ���������������� ���� VID/PID.
    ���������� ������� USBID-License.txt!
 * + ���� ������ ���������� ����� ���� VID/PID �� obdev: 0x16c0/0x5dc.
 * + ����������� ��� ���� VID/PID ������ ���� �� ��������� ����� �����!
 */
#define USB_CFG_DEVICE_VERSION  0x00, 0x01
/* ����� ������ ����������: ������� ������� �����, ����� ������� �����.
 */
#define USB_CFG_VENDOR_NAME     'B', 'o', 'j', 'o', 'k'
#define USB_CFG_VENDOR_NAME_LEN 5
/* ��� ��� �������� ������ ��� ������� (vendor name), ������������ �����������. 
    ��� ������ ��������������� ��� ������ �������� � ��������� ��������. 
    ������� ���������������� ��� Unicode (UTF-16). ���� ��� �� ����� ��� �������,
    ��������������� ���� ������. ������ ���������� ��� �������, ���������� ���� 
    �������� ��� Internet, ���� �� ����������� �������� ���������������� ���� 
    obdev VID/PID. �� �������� ����������� � ����� USBID-License.txt.
 */
#define USB_CFG_DEVICE_NAME     'T', 'o', 'k', 'e', 'n'
#define USB_CFG_DEVICE_NAME_LEN 5
/* ����� ����������� ��� ���������� (device name) ����� �� ��������, ��� � � ���������� 
    ��������� ����������� ��� �������. ���� ��� �� ����� ��� ����������, ���������������
    ���� ������. ��. ���� USBID-License.txt ����� ����������� �����, ���� �� ����������� 
    �������� ���������������� ���� obdev VID/PID.
 */
/*#define USB_CFG_SERIAL_NUMBER   'N', 'o', 'n', 'e' */
/*#define USB_CFG_SERIAL_NUMBER_LEN   0 */
/* �������� ����� (serial number). ���� �������� ����� ��� �� �����, ��������������� ������.
    ����� ��������� �������� ������������� serial number �� ������ ������������, ������������ 
    �� ������� ����������. ��. ������, ����������� �������� ����������� �����, ��� ������� 
    ��� ������� ������ ���������� ������������� USB (USB descriptors), ������ ��� ���������
    ��������� ��� ��������� ������.
 */
#define USB_CFG_DEVICE_CLASS        0    /* ������� 0, ���� deferred to interface */
#define USB_CFG_DEVICE_SUBCLASS     0
/* ��. ������������ USB, ���� �� ������ ������������ ���������� � ������������� ������ ��������� 
    (device class). ����� 0xff �������� "������������� ��� �������" ("vendor specific").
 */
#define USB_CFG_INTERFACE_CLASS     3   /* ������� ����� �����, ���� ��� �� ������� �� ������ ���������� */
#define USB_CFG_INTERFACE_SUBCLASS  0
#define USB_CFG_INTERFACE_PROTOCOL  0
/* ��. ������������ USB, ���� �� ������, ����� ���������� �������� ����������� ������������� ������
    ��� ���������. ��������� ������ ������ ���� ����������� �� ������ ����������:
 * HID class 3, ����������� ���������� � ���������� (����� ��������� �������!)
 * CDC class 2, ����������� �������� 2 � �������� 1 ��� ACM
 */
#define USB_CFG_HID_REPORT_DESCRIPTOR_LENGTH    48 
/* ������� ����� ����� HID report descriptor, ���� �� ����������� HID-����������. 
    ����� �� ��������� ���� �������� ��� ���������� ��� � 0.
   ���� ����������� ��� ����������, �� �� ������ �������� ���������� ������ PROGMEM, ���������
    "usbHidReportDescriptor", � ���, ������� �������� report descriptor. �� �������� �������
    ������ � ���� �������� � ������������!
 */

/* #define USB_PUBLIC static */
/* ����������� ���� define, ���� �� ����������� ��������� #include usbdrv.c ������ ����������.
    ��� ������� �������� ��������� ���� flash-������.
 */

/* ------------------- ������ ���������� ����� ����������� USB ------------------- */
/* ���� �� �� ������ ������������ ����������� �� ��������� �������� USB, �� ������
    ������������ ���� �����������. ��� ����� ���� ������� ��� (1) ����������� ������ 
    ������������� ����� � ������ flash, (2) ����������� ������ ������������� ����� � RAM, 
    ��� (3) ������������ �� ����� ���������� � ������� usbFunctionDescriptor(). 
    ��. usbdrv.h ��� ������� ���������� �� ���� �������.
   ��������� ������������ ��������������� ����� �������� �����������. ���� �� ������ 
    �������� ��� ���� ��� ����� 0, ������������ ���������� �� ���������.
   �������� ��������:
     + USB_PROP_IS_DYNAMIC: ������ ��� ����������� ������ ���� ��������� (fetched)
       �� ����� ���������� ����� usbFunctionDescriptor().
     + USB_PROP_IS_RAM: ������, ������������ usbFunctionDescriptor() ��� ��������� 
       � ����������� ������ RAM, �� � ������ flash.
     + USB_PROP_LENGTH(len): ���� ������ � ����������� ������ (RAM ��� flash),
       ������� ������ ����� ����� �����������. ���������� ��� �� ���� ������ �� ������,
       ���������� ��� ������������� (��. �����).
   ������ ����������� ���� ������������ (������ ���� �������������� PROGMEM � flash):
     char usbDescriptorDevice[];
     char usbDescriptorConfiguration[];
     char usbDescriptorHidReport[];
     char usbDescriptorString0[];
     int usbDescriptorStringVendor[];
     int usbDescriptorStringDevice[];
     int usbDescriptorStringSerialNumber[];
   ������ ����������� �� ����� ���� ������������� ����������, ��� ������ ��������������� 
   ����������� �� ����� ����������.
 
   �������� ������������ ������������ �� ��� ���� ������������ ������, ��������:
   #define USB_CFG_DESCR_PROPS_DEVICE   (USB_PROP_IS_RAM | USB_PROP_LENGTH(18))
 
   ��������� ����������� ������:
     USB_CFG_DESCR_PROPS_DEVICE
     USB_CFG_DESCR_PROPS_CONFIGURATION
     USB_CFG_DESCR_PROPS_STRINGS
     USB_CFG_DESCR_PROPS_STRING_0
     USB_CFG_DESCR_PROPS_STRING_VENDOR
     USB_CFG_DESCR_PROPS_STRING_PRODUCT
     USB_CFG_DESCR_PROPS_STRING_SERIAL_NUMBER
     USB_CFG_DESCR_PROPS_HID
     USB_CFG_DESCR_PROPS_HID_REPORT
     USB_CFG_DESCR_PROPS_UNKNOWN (��� ���� ������������, �� �������������� ���������)
  */

#define USB_CFG_DESCR_PROPS_DEVICE                  0
#define USB_CFG_DESCR_PROPS_CONFIGURATION           0
#define USB_CFG_DESCR_PROPS_STRINGS                 0
#define USB_CFG_DESCR_PROPS_STRING_0                0
#define USB_CFG_DESCR_PROPS_STRING_VENDOR           0
#define USB_CFG_DESCR_PROPS_STRING_PRODUCT          0
#define USB_CFG_DESCR_PROPS_STRING_SERIAL_NUMBER    0
#define USB_CFG_DESCR_PROPS_HID                     0
#define USB_CFG_DESCR_PROPS_HID_REPORT              0
#define USB_CFG_DESCR_PROPS_UNKNOWN                 0

/* ----------------------- �������������� �������� MCU ------------------------ */
/* ��������� ������������ �������� �� ��������� � usbdrv.h. ��� ������ �� �����
    ������������� ��. ������ ���� ��� ����� ��������� ������� �� ����������,
    ������� ���� �� �������������� ������������, ������� �� ��������� �������������� 
    (���, ��������, IAR C) ��� ���� ����������� ����������, �������� �� INT0, 
    �� ������ ������ ���-��� �� �����.
 */
/* #define USB_INTR_CFG            MCUCR */
/* #define USB_INTR_CFG_SET        ((1 << ISC00) | (1 << ISC01)) */
/* #define USB_INTR_CFG_CLR        0 */
/* #define USB_INTR_ENABLE         GIMSK */
/* #define USB_INTR_ENABLE_BIT     INT0 */
/* #define USB_INTR_PENDING        GIFR */
/* #define USB_INTR_PENDING_BIT    INTF0 */
/* #define USB_INTR_VECTOR         SIG_INTERRUPT0 */

#endif /* __usbconfig_h_included__ */
