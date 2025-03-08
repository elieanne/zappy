def open_file(file_name: str) -> str:
    """Open a file (if it exists).

    :param str file_name: the filename.

    :return str: file content or an empty string if the file doesn't exist.
    """
    try:
        file = open(file_name, "r")
        content = file.read()
        file.close()
        return content
    except IOError:
        return ""
