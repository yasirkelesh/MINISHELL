# MINISHELL

Bu proje, Bash programının bir taklidi olarak yazılmıştır. Proje, C dili kullanılarak Ecole 42'de geliştirilmiştir. Projenin amacı, Bash programlarının temel fonksiyonlarını taklit etmek ve execve fonksiyonunu kullanarak diğer programları çalıştırmaktır.

**Proje, aşağıdaki Bash komutlarının taklitlerini içermektedir**

- cd: Dizin değiştirmek için kullanılır.
- echo: Konsola bir metin yazdırmak için kullanılır.
- pwd: Geçerli dizinin yolunu yazdırmak için kullanılır.
- export: Sistem değişkenlerini oluşturmak veya değiştirmek için kullanılır.
- unset: Sistem değişkenlerini silmek için kullanılır.
- env: Sistem değişkenlerini listelemek için kullanılır.

**Ayrıca projede, aşağıdaki fonksiyonları kullanmaktadır**

- pipe: Bir komutun çıktısını başka bir komutun girdisi olarak kullanmayı sağlar.
- dup: Bir dosya tanıtıcısının çiftine yönlendirme yapar.
- dup2: Bir dosya tanıtıcısının çiftine yönlendirme yapar ve eski çifti kapatır.
- readline: Kullanıcıdan satır bazlı girdi almak için kullanılır.
- execve: Bir programı çalıştırmak için kullanılır.
- heredoc: Komut satırından okunan veriyi belirli bir formatta yazdırmak için kullanılır.
- Installation and Usage

**Projeyi kurmak ve kullanmak için aşağıdaki adımları izleyin**

1. Projenin kaynak kodlarını GitHub sayfasından indirin veya klonlayın.
2. Projenin klasörüne gidin ve makefile kullanarak projeyi derleyin: make
3. Derleme işlemi tamamlandıktan sonra, projeyi çalıştırmak için aşağıdaki komutu kullanın:
./minishell
4. Önemli Not: Projeyi çalıştırmak için sisteminizde readline kütüphanesi yüklü olması gerekir, eğer yüklü değilse macOS için "brew install readline" komutunu kullanabilirsiniz.

Proje, execve fonksiyonunu kullanarak çalıştırdığınız diğer programların çıktılarını görüntüler. Ayrıca taklit ettiğimiz Bash komutlarını kullanarak sistem üzerinde gezinmenizi ve değişkenleri yönetmenizi sağlar. Projede ayrıca pipe ve redir mantığını kullanarak çıktıların yönlendirilmesini ve heredoc fonksiyonu ile komut satırından veri alınmasını sağlar. Özellikle, "command1 | command2" gibi pipe kullanımı, "command1 > output.txt" gibi redirection kullanımı ve heredoc kullanımı gibi senaryolarda projenizin nasıl çalıştığını gözlemleyebilirsiniz.

Proje ayrıca "$?" çıkış durumlarını kontrol etme, ctrl-C ve ctrl-D kullanarak programın sonlandırılması, "cd" komutu ile dizine gitme gibi senaryolarda test edilmiştir. Bu sayede projenizin ne kadar stabil ve verimli olduğunu ve hangi senaryolarda çalıştığını gözlemleyebilirsiniz.
