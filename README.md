# Lorem Redis Module #

A simple Redis module, just as an example.

Adds 'LOREM.IPSUM' command, returns string with the expected text.

Run `make` to create the `lorem.so` module. Load into a Redis server (unstable branch for now) with:

    LOAD MODULE /path/to/lorem.so

Then you can run

    LOREM.IPSUM

Simple.

## License

See LICENSE file for details.
