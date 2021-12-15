export const ResultModal = (props) => {
    return (
        <div id="modal1" className="modal bottom-sheet">
            <div className="modal-content">
                <h4>Modal Header</h4>
                <p>A bunch of text</p>
            </div>
            <div className="modal-footer">
                <a
                    href="#!"
                    className="modal-close waves-effect waves-green btn-flat"
                >
                    Agree
                </a>
            </div>
        </div>
    );
};
