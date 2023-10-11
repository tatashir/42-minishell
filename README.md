# 42-minishell

miniShellは、シンプルなシェルの実装。コマンドラインを受け取り、ビルトインコマンドを実行し、外部コマンドを実行する機能を提供する。また、パイプやリダイレクションなどの基本的な機能もサポートしている。

## コンパイルと実行

プログラムをコンパイルして実行するためには、次の手順を実行してください：

```bash
make
./minishell
```

## 使用方法

MiniShellは対話型のシェルとして使用できます。プロンプトが表示されるので、コマンドを入力して実行できます。

```bash
$ ./minishell
> echo Hello, MiniShell!
Hello, MiniShell!
>
```

終了するには、`exit`コマンドを入力します。

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

## 依存関係

このプログラムは以下の依存関係を持っています：

- [GNU Readline](https://tiswww.case.edu/php/chet/readline/rltop.html)

## ライセンス

このプロジェクトはMITライセンスのもとで公開されています。詳細については、[LICENSE](LICENSE)ファイルを参照してください。
