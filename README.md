Para usar a biblioteca mailio no visual studio (tive muito problema pra intalar ela, mas é simples), escolha um lugar para instalar ela, em seguida abra o cmd como administrador vá até o local da pasta e siga a sequencia se comandos:

> git clone https://github.com/microsoft/vcpkg
> .\vcpkg\bootstrap-vcpkg.bat
> .\vcpkg\vcpkg install mailio:x64-windows
> .\vcpkg\vcpkg integrate install

Pronto, ela está em uso no seu Visual Studio 2022 (esses passos funcionaram comigo, não sei se vai funcionar completamente).

===========================================================================

To use the mailio library in visual studio (I had a lot of trouble installing it, but it's simple), choose a place to install it, then open cmd as administrator, go to the location of the folder and follow the sequence of commands:

> git clone https://github.com/microsoft/vcpkg
> .\vcpkg\bootstrap-vcpkg.bat
> .\vcpkg\vcpkg install mailio:x64-windows
> .\vcpkg\vcpkg integrate install

That's it, it's in use in your Visual Studio 2022 (these steps worked for me, I don't know if it will work completely).