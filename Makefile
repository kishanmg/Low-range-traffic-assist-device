NRTADGateway: nrtadgateway.c
	gcc nrtadgateway.c -o NRTADGateway

NRTADevice: nrtadevice.c
	gcc nrtadevice.c -o NRTADevice

all: NRTADGateway NRTADevice

clean:
	rm NRTADGateway
	rm NRTADevice
