#!/bin/bash

# Define the directory to check for .bin files
USB_DIR="/media/usb"

# Wait for the USB drive to mount
sleep 5

# Check if the USB drive is mounted
if mount | grep -q "$USB_DIR"; then
    echo "USB drive is mounted."

    # Find the first .bin file in the USB directory
    BIN_FILE=$(find "$USB_DIR" -maxdepth 1 -type f -name "*.bin" | head -n 1)

    # Check if a .bin file was found
    if [ -n "$BIN_FILE" ]; then
        echo "Executing $BIN_FILE..."
        # Execute the .bin file
        chmod +x "$BIN_FILE"  # Ensure it's executable
        "$BIN_FILE"            # Execute the file
        echo "Execution completed."
    else
        echo "Error: No .bin file found in $USB_DIR."
    fi
else
    echo "Error: USB drive is not mounted."
fi
