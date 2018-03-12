# Jumper Virtual Lab Peripheral Model - AT25SF081
This repo contains a model for the AT25SF081 flash SPI device for [Jumper Virtual Lab](https://vlab.jumper.io).

For more information, visit [the docs](https://docs.jumper.io).

### Prerequisites
- GCC and Make: `apt install build-essential`
- [Jumper Virtual Lab](https://docs.jumper.io)

## Usage
- Follow the following steps in order to build the peripheral model:

  ```bash
  git clone https://github.com/Jumperr-labs/at25sf081.git
  cd at25sf081
  make
  ```

- If the peripheral model was build successfully, the result will be ready under "_build/AT25SF081.so".
Copy this file to you working diretory, same one as the "board.json" file.
- Add the following component in your "board.json" file. Make sure to change the pin numbers to fit your configuration.

```json
{
  "name": "AT25SF081",
  "id": 2,
  "type": "Peripheral",
  "file": "AT25SF081.so",
  "config": {
    "pins": {
      "wp": 1,
      "cs": 2,
      "sck": 3,
      "si": 4,
      "so": 5,
      "hold": 6
    }
  }
}
```

## License
Licensed under the Apache License, Version 2.0. See the LICENSE file for more information
