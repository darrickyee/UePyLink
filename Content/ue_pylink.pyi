from typing import Optional

def dispatch(name: Optional[str] = None, data: Optional[str] = None) -> None:
    """Dispatches an event to Unreal by calling the OnDispatch event dispatcher.

    Args:
        name (str, optional): String to be passed to the Name parameter.  Value will be coerced to FName.
        data (str, optional): String to be passed to the Data parameter (as an FString).
    """
    ...

def log(message: Optional[str] = None) -> None:
    """Logs a message to the UE4 output console.

    Args:
        message (str, optional): The message to log.
    """
    ...