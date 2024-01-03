ARG VARIANT=focal
FROM mcr.microsoft.com/vscode/devcontainers/cpp:${VARIANT}
# COPY library-scripts/github-debian.sh /tmp/library-scripts/
RUN apt update -y
RUN apt install python3 python3-pip clangd -y
RUN pip install --upgrade pip setuptools
RUN pip install norminette
# RUN bash /tmp/library-scripts/github-debian.sh
