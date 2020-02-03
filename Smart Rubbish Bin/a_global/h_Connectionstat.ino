//Connection Status

void connectionStatus(byte statusCode)
{
  /* Check connection code and display. */
  switch(statusCode)
  {
    case CONNECTION_SUCCESSFUL: Terminal.println("CONNECTION_SUCCESSFUL");break;
    case CONNECTION_FAILED: Terminal.println("CONNECTION_FAILED");break;
    case CONNECTION_LOST: Terminal.println("CONNECTION_LOST");break;
    case CONNECTION_LOST_RECONNECTING: Terminal.println("CONNECTION_LOST_RECONNECTING");break;
    case NOT_CONNECTED_YET:  Terminal.println("NOT_CONNECTED_YET");break;
    case MISSING_HOST: Terminal.println("MISSING_HOST");break;
  }
}
