from xml.etree import ElementTree
import os
import sys


def list_typesystem_cpp_sources(typesystem, out):
    tree = ElementTree.parse(typesystem)
    root = tree.getroot()

    package = root.attrib["package"]

    types = []
    parentList = [(root, "")]
    while len(parentList) > 0:
        (parent, prefix) = parentList.pop(0)
        for child in parent:
            if child.tag == 'namespace-type':
                newPrefix = child.attrib["name"]
                if len(prefix) > 0:
                    newPrefix = "{}_{}".format(prefix, newPrefix)
                parentList.append((child, newPrefix))

            if child.tag in ["object-type", "value-type"]:
                typeName = child.attrib["name"]
                if len(prefix):
                    typeName = "{}_{}".format(prefix, typeName)
                types.append(typeName)

    sources = [f"{package.lower()}_module_wrapper.cpp"]
    sources.extend([f"{typename.lower()}_wrapper.cpp" for typename in types])

    return [os.path.normpath(os.path.join(out, package, f)) for f in sources]


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("usage: sourceList.py <typesystem> <gen-directory>", file=sys.stderr)
        exit(1)
    print(";".join(list_typesystem_cpp_sources(sys.argv[1], sys.argv[2])), end='')
