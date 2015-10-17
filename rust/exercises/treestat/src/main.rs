// Modify stat_tree to spawn off a child thread for each subdirectory. In other
// words, the recursive calls should take place in new threads. You'll need to
// collect the JoinHandles in a Vec, and then after the main `for` loop is done,
// loop over the handles, join them, collect their results, and append them to
// the result vector.
//
// Remember that you can't let spawned threads borrow things from their parent
// threads: there's no guarantee that the spawned thread won't outlast their
// parents.

use std::fs;
use std::io;
use std::path::{Path, PathBuf};

pub type StatVec = Vec<(PathBuf, fs::Metadata)>;

fn stat_tree(dir: &Path) -> io::Result<StatVec> {
    let mut result = Vec::new();

    for entry in try!(fs::read_dir(dir)) {
        let entry = try!(entry);
        let pathbuf = entry.path();
        let metadata = try!(entry.metadata());
        if metadata.is_dir() {
            let stat_vec = try!(stat_tree(&pathbuf));
            result.extend(stat_vec);
        }
        result.push((entry.path(), metadata));
    }

    Ok(result)
}

fn main() {
    for arg in std::env::args_os().skip(1) {
        let results = stat_tree(Path::new(&arg)).unwrap();
        for (path, metadata) in results {
            println!("{:?}: {:?}", path, metadata.len());
        }
    }
}
