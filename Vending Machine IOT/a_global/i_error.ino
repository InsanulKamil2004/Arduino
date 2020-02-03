//Error

void error(byte errorCode)
{
  /* Check error code and display. */
  switch(errorCode)
  {
    case CONNECTION_REFUSED                    : Terminal.println("CONNECTION_REFUSED");break;
    case ILLEGAL_MESSAGE_RECEIVED              : Terminal.println("ILLEGAL_MESSAGE_RECEIVED");break;
    case DROPPING_OUT_GOING_MESSAGE            : Terminal.println("DROPPING_OUT_GOING_MESSAGE");break;
    case ENCODER_NOT_READY                     : Terminal.println("ENCODER_NOT_READY");break;
    case INVALID_CONNACK_RECEIVED              : Terminal.println("INVALID_CONNACK_RECEIVED");break;
    case NO_CONNACK_RECEIVED                   : Terminal.println("NO_CONNACK_RECEIVED");break;
    case CONNACK_UNACCEPTABLEP_ROTOCOLVERSION  : Terminal.println("CONNACK_UNACCEPTABLEP_ROTOCOLVERSION");break;
    case CONNACK_IDENTIFIER_REJECTED           : Terminal.println("CONNACK_IDENTIFIER_REJECTED");break;
    case CONNACK_SERVER_UNAVAILABLE            : Terminal.println("CONNACK_SERVER_UNAVAILABLE");break;
    case CONNACK_AUTHENTICATION_FAILED         : Terminal.println("CONNACK_AUTHENTICATION_FAILED");break;
    case CONNACK_NOT_AUTHORIZED                : Terminal.println("CONNACK_NOT_AUTHORIZED");break;
    case CONNACK_RESERVED                      : Terminal.println("CONNACK_RESERVED");break;
  }
} 
