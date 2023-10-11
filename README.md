# 42-minishell

42の課題でbashを自作。パイプやリダイレクトもサポート。

## コンパイルと実行

```bash
make
./minishell
```

## 使用方法

readlineがインストールされいている必要があります。

```bash
$ ./minishell
> echo Hello, MiniShell!
Hello, MiniShell!
>
```

`exit`コマンドで終了します。

```bash
> exit
$ 
```

## ビルトインコマンド

MiniShellには以下のビルトインコマンドが組み込まれています：

- `echo`: テキストの表示
- `cd`: ディレクトリの変更
- `pwd`: 現在の作業ディレクトリの表示
- `export`: 環境変数の設定
- `unset`: 環境変数の削除
- `env`: 環境変数の表示
- `exit`: プログラムの終了
