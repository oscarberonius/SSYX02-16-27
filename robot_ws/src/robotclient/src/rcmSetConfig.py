#!/usr/bin/env python
PKG = 'numpy'
import numpy as np


def swapbytes16(x):
    """

    :param x: A 16-bit unsigned integer or array of integers.
    :return: The reverse order of the bytes of the given number or array.
    The given number 0xABCD would return 0xCDAB.
    """
    return ((x << 8) | (x >> 8)) & 0xFFFF


def swapbytes32(x):
    """

    :param x: A 32-bit unsigned integer or array of integers.
    :return: The reverse order of the bytes of the given number or array.
    The given number 0x89ABCDEF would return 0xEFCDAB89.
    """
    return (((x << 24) & 0xFF000000) |
            ((x << 8) & 0x00FF0000) |
            ((x >> 8) & 0x0000FF00) |
            ((x >> 24) & 0x000000FF))


def typecast(x, t):
    """

    :param x: A number or array of numbers to be typecasted.
    :param t: The desired new type. 16 would produce a unsigned 16-bit integer or array of integers.
    :return: The given number typecasted to its new type. The 16-bit hex number 0xFACE typecasted to 8-bit would return
    a 8-bit array containing [0xFA, 0xCE]. Likewise the 8-bit array [0xDE, 0xAD, 0xBE, 0xEF] typecasted to 32-bit would
    return the 32-bit integer 0xDEADBEEF.
    """
    if t == 8:
        x.dtype = np.uint8
    elif t == 16:
        x.dtype = np.uint16
    elif t == 32:
        x.dtype = np.uint32
    return x


def setConf(s, rcmIp, config):
    """

    :param s: The socket that is used to communicate between the computer and the RCM connected via ethernet cable.
    :param rcmIp: The IP of the RCM whose configuration is sought to set.
    :param config: The configuration to be sent to the RCM.
    :return: the status of the response from the RCM.
    """
    status = np.empty(0xFF, dtype=np.uint8)  # was not instantiated before, probably best even though it is never used
    port=21210  # rcm port

    MSG_TYPE = swapbytes16(np.array([int('0001', 16)], dtype=np.uint16))  # RCM_SET_CONFIG_REQUEST message type.
    MSG_ID = swapbytes16(np.array([int('0003', 16)], dtype=np.uint16))
    NODE_ID = swapbytes32(np.array(config[1], dtype=np.uint32))
    PII = swapbytes16(np.array(config[2], dtype=np.uint16))
    ANTMODE = np.array(config[3], dtype=np.uint8)
    CODE = np.array(config[4], dtype=np.uint8)
    ANTDELAYA = swapbytes32(np.array(config[5], dtype=np.uint32))
    ANTDELAYB = swapbytes32(np.array(config[6], dtype=np.uint32))
    FLAGS = swapbytes16(np.array(config[7], dtype=np.uint16))
    TXGAIN = np.array(config[8], dtype=np.uint8)
    PERSIST = np.array(config[12], dtype=np.uint8)  # config.persistFlag

    RCM_SET_CONFIG_REQUEST = np.concatenate([typecast(np.array([MSG_TYPE[0], MSG_ID[0]], dtype=np.uint16), 8),
                                             typecast(np.array([NODE_ID[0]], dtype=np.uint32), 8),
                                             typecast(np.array([PII[0]], dtype=np.uint16), 8),
                                             ANTMODE, CODE,
                                             typecast(np.array([ANTDELAYA[0], ANTDELAYB[0]], dtype=np.uint32), 8),
                                             typecast(np.array([FLAGS[0]], dtype=np.uint16), 8),
                                             TXGAIN, PERSIST])
    RCM_SET_CONFIG_REQUEST.dtype = np.uint8
    RCM_SET_CONFIG_REQUEST = bytearray(RCM_SET_CONFIG_REQUEST)

    # send data
    s.sendto(RCM_SET_CONFIG_REQUEST, (rcmIp, port))
    timeout = 400  # time in ms
    PACKET_LENGTH = 8  # size in byte
    s.settimeout(timeout)
    msg, msgAddr = s.recvfrom(PACKET_LENGTH)
    msg = bytearray(msg)  # Unpack string to byte array

    # processing response
    msgType = typecast(np.array([msg[1], msg[0]], dtype=np.uint8), 16)
    if msgType != np.array([int('0101', 16)], dtype=np.uint16):
        print 'Message type %04x does not match RCM_SET_CONFIG_CONFIRM. ', msgType
        config=np.empty(PACKET_LENGTH)
    else:
        # msgId in confirm should be equal to msgId in request
        msgId = typecast(np.array([msg[3], msg[2]], dtype=np.uint8), 16)
        status = typecast(np.array([msg[7], msg[6], msg[5], msg[4]], dtype=np.uint8), 32)
    return status