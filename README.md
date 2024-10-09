<p align="center">
  <a href="https://github.com/aligungr/UERANSIM"><img src="/.github/logo.png" width="75" title="UERANSIM"></a>
</p>
<p align="center">
<img src="https://img.shields.io/badge/UERANSIM-v3.2.6-blue" />
<img src="https://img.shields.io/badge/3GPP-R15-orange" />
<img src="https://img.shields.io/badge/License-GPL--3.0-green"/>
</p>

**UERANSIM** <small>(pronounced "ju-i ræn sɪm")</small>, is the open source state-of-the-art 5G UE and RAN (gNodeB)
simulator. UE and RAN can be considered as a 5G mobile phone and a base station in basic terms. The project can be used for
testing 5G Core Network and studying 5G System.

UERANSIM introduces the world's first and only open source 5G-SA UE and gNodeB implementation.

**WARNING:** I'm no longer active in the development of UERANSIM. However community contributions are welcomed.

## Current Status

Basic functionalities of UE and gNodeB are fully functional and ready to use. However some of the features are not complete.
More details can be found at [Feature Set](https://github.com/aligungr/UERANSIM/wiki/Feature-Set).

On the other hand, UERANSIM does not fully provide physical layer. 5G-NR radio interface is partially implemented, and simply simulated over UDP protocol.

<p align="center">
<img src="https://img.shields.io/badge/Radio%20Interface-simulated-orange" alt="OS Linux"/>
<img src="https://img.shields.io/badge/Control%20Plane-functional-green" alt="OS Linux"/>  
<img src="https://img.shields.io/badge/User%20Plane-functional-green" alt="OS Linux"/>
</p>

## Documentation

You can find the documentation on [UERANSIM Wiki](https://github.com/aligungr/UERANSIM/wiki).

And, since the project is rapidly developing, please make sure that you have always
the [latest](https://github.com/aligungr/UERANSIM/releases) UERANSIM.

## Contributing

Any contributions you make are greatly appreciated via [Pull Request](https://github.com/aligungr/UERANSIM/pulls).

## Supporting

You can support UERANSIM by:

- Starring the GitHub repository,
- Donating on [Open Collective](https://opencollective.com/UERANSIM)
- Creating pull requests, submitting bugs, suggesting new features or documentation updates.

## ASN1C installation
To update **asn1c**, you can follow the steps below depending on the operating system you're using. If you're using **Ubuntu** or a **Debian-based** distribution, here’s the guide:

### 1. **Remove the Old Version (Optional)**
   If you already have an older version of `asn1c`, you can remove it first with the following command:

   ```bash
   sudo apt-get remove asn1c
   ```

### 2. **Install ASN.1 Compiler from Source**
   Since the `asn1c` package available in the default repository is often outdated, the best way to get the latest version is by downloading and compiling it from the source. Here are the steps:

   a. **Install Prerequisites**:
   Before compiling `asn1c`, ensure that you have installed the necessary tools, such as `git`, `autoconf`, and `build-essential`:

   ```bash
   sudo apt-get update
   sudo apt-get install git autoconf build-essential
   ```

   b. **Clone the `asn1c` Repository from GitHub**:
   You can download the latest source code of `asn1c` from GitHub:

   ```bash
   git clone https://github.com/vlm/asn1c.git
   ```

   c. **Enter the Directory and Compile**:

   ```bash
   cd asn1c
   git submodule update --init
   autoreconf -iv
   ./configure
   make
   sudo make install
   ```

   This will install the latest version of `asn1c` on your system.

### 3. **Verify the Installation**
   After the installation is complete, verify that `asn1c` has been updated by running the following command:

   ```bash
   asn1c -v
   ```
  the required version is **v0.9.29**
   You will see the latest installed version displayed.

By following these steps, you will have the latest version of `asn1c` installed on your system. If you want to compile ASN.1 files into **`.h`** (header) and **`.c`** (source code) files using the ASN.1 Compiler (`asn1c`), here are the steps you can follow:

### 1. **Ensure `asn1c` is Installed**
   If it’s not installed yet, make sure you’ve installed `asn1c` according to the instructions previously explained.

### 2. **Compile ASN.1 Files into `.h` and `.c` Files**

   Suppose you're in the directory that contains the ASN.1 files, for example:

   ```bash
   cd tool/f1ap/ASN1/R16.3.1
   ```

   Run the following command to compile all ASN.1 files into **`.h`** and **`.c`** files:

   ```bash
  sudo asn1c -fcompound-names -gen-PER -D . *.asn
   ```

   These options mean:
   - `-fcompound-names`: Prevents name clashes by generating longer type names (in case there are types with the same name).
   - `-gen-PER`: Generates code for PER (Packed Encoding Rules) encoder/decoder.
   
   **Note:** You can add other options such as `-findirect-choice` if there are CHOICE types that need to be processed as pointers.

### 3. **Check the Results**
   After compiling, you will get **`.c`** and **`.h`** files in the same directory. For instance, if there’s an ASN.1 file defining the F1AP type, you might get files like:

   - `F1AP-IEs.c`
   - `F1AP-IEs.h`
   - `F1AP-Constants.c`
   - `F1AP-Constants.h`

### 4. **Compile the C Code**
   Once you have the **`.h`** and **`.c`** files, you can compile them using **gcc** or another C compiler:

   ```bash
   gcc -o f1ap_example *.c -lm
   ```

   The `-lm` option is used to link the math library if needed.

### Complete Example Steps:

1. **Enter the directory containing the ASN.1 files**:

   ```bash
   cd tool/f1ap/ASN1/R16.3.1
   ```

2. **Run `asn1c` to compile the ASN.1 files into `.h` and `.c` files**:

   ```bash
   asn1c -fcompound-names -gen-PER *.asn
   ```

3. **Check the results**: Look at the `.h` and `.c` files generated in the directory.

4. **Compile with gcc**:

   ```bash
   gcc -o f1ap_example *.c -lm
   ```

After these steps, you will have an executable that can be used to run the code generated from the ASN.1 files.

## License

Copyright (c) 2022 ALİ GÜNGÖR.

All source code and related files including documentation and wiki pages are
dual licensed with [GPL-3.0](https://www.gnu.org/licenses/gpl-3.0.en.html) and a commercial license.

Commercial usage of UERANSIM is **not** permitted with the GPL-3.0. If GPL-3.0 license is not compatable with your use case, please contact [ueransim@gmail.com](mailto:ueransim@gmail.com) to buy a commercial license.
