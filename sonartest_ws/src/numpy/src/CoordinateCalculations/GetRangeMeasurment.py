#!/usr/bin/env python
PKG = 'numpy'
import rcmSendRangeRequest


def measRange(s, reqIp, respId, doPrint):
    """

    :param s: The socket that is used to communicate between computer and RCM through a wired connection
    :param reqIp: The ip of the RCM that is connected via an ethernet cable.
    :param respId: The id of the node which distance to the RCM is sought.
    :param doPrint: Not used at this moment. In the future this variable may be used to decide whether or not some
    technical information about the measuring process should be printed
    :return: The measured range between the node and the robot.
    """
    msgId = 0
    attempt = 0
    success = 0
    calcRange = 0
    while success < 1:
        msgId = (msgId + 1) % (0xffff+1)  # contains information about how many times the range have been requested.
        # checks if the RCM is ready to transmit the measured range.
        status, msgIdCfrm = rcmSendRangeRequest.reqRange(s, reqIp, msgId, respId)
        attempt += 1
        if status[0] == 0:
            # receive information about the measured range and if it was successful.
            rangeInfoStatus, rangeInfoFre = rcmSendRangeRequest.rcmMinimalRangeinfo(s)
            if rangeInfoStatus[0] == 0:  # successful measurement
                success = 1
                calcRange = rangeInfoFre[0]/1000
            elif rangeInfoStatus[0] == 1:
                print 'range timeout\n'
            elif rangeInfoStatus[0] == 2:
                print 'LED failure\n'
            elif rangeInfoStatus[0] == 9:
                print 'UDP failure on InfoReceive\n'
            else:
                print 'UDP failure on InfoReceive\n'

        if attempt > 10:
            print 'Error in measuring range'

    return calcRange

